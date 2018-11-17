/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 08:17:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/17 20:23:19 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h> //
#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <grp.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include "ft_ls.h"

int		set_option(void *container, char option)
{
	int			*i;
	t_options	*p;

	i = NULL;
	p = (t_options *)container;
	if (option == 'a')
		i = &p->a;
	else if (option == 'R')
		i = &p->ur;
	else if (option == 'l')
		i = &p->l;
	else if (option == 'r')
		i = &p->r;
	else if (option == 't')
		i = &p->t;
	if (i)
		*i = 1;
	return (i ? 1 : 0);
}

void	basic_outp(t_options *ops, t_list *dirs, int fl_not_empty, int files_not_empty)
{
	if (dirs && files_not_empty)
		printf("\n%s:\n", ((t_entry *)dirs->content)->full_path);
	else if (dirs && fl_not_empty)
		printf("%s:\n", ((t_entry *)dirs->content)->full_path);
	while (dirs)
	{
		print_dir(((t_entry *)dirs->content)->full_path, ops);
		dirs = dirs->next;
		if (fl_not_empty && dirs)
			printf("\n%s:\n", ((t_entry *)dirs->content)->full_path);
	}
}

static void init_lists(t_list **dirs, t_list **files, int argc, char **argv, t_options *ops)
{
	int			i;
	mode_t		mode;
	struct stat buf;

	i = -1;
	while (++i < argc)
	{
		if (!lstat(argv[i], &buf))
		{
			mode = buf.st_mode;
			if (S_ISDIR(mode) || (S_ISLNK(mode) && !ops->l))
				ft_lstadd(dirs, ft_lstnew_cc(
							ft_entrynew(argv[i], argv[i]), sizeof(t_entry)));
			else
				ft_lstadd(files, ft_lstnew_cc(
							ft_entrynew(argv[i], argv[i]), sizeof(t_entry)));
		}
	}
}

static void	check_for_garbage(int argc, char **argv)
{
	size_t		len;
	char		*tmp;
	int			i;
	struct stat	buf;

	i = 0;
	while (i < argc)
	{
		if (lstat(argv[i], &buf))
		{
			tmp = ft_format("ft_ls: %s: No such file or directory\n", &len, argv[i]);
			ft_putstr_fd(tmp, 2);
			free(tmp);
		}
		++i;
	}
}

void	delentry(void *content, size_t content_size)
{
	t_entry *ent;

	content_size = 0;
	ent = (t_entry *)content;
	free(ent->name);
	free(ent->full_path);
	free(ent);
}

int		main(int argc, char **argv)
{
	char			*tmp;
	t_options		ops;
	t_pos			pos;
	int				vld;
	t_list			*files;
	t_list			*dirs;

	vld = argc - 1;
	files = NULL;
	dirs = NULL;
	ft_bzero((void *)&ops, sizeof(t_options));
	pos = ft_argsparser_ti(&argv[1], &vld, (void*)&ops, set_option);
	if (vld == 1 || ((pos.y >= argc - 1) && vld == 3))
		ft_lstadd(&dirs, ft_lstnew_cc(ft_entrynew(".", "."), sizeof(t_entry)));
	else if (vld == 0)
	{
		if (vld == 0)
		{
			printf("ft_ls: illegal option -- %c\n", argv[pos.y + 1][pos.x]);
			return (42);
		}
		else
		{
			tmp = ft_strjoin("ft_ls: ", argv[pos.y + 1]);
			perror(tmp);
			free(tmp);
			return (43);
		}
	}
	init_lists(&dirs, &files, argc - pos.y - 1, &argv[pos.y + 1], &ops);
	if (files && files->next)
		sort_list(&ops, &files);
	if (dirs && dirs->next)
		sort_list(&ops, &dirs);
	check_for_garbage(argc - pos.y - 1, &argv[pos.y + 1]);
	print_files(files, &ops);
	if (ops.ur && dirs)
		big_r(dirs, &ops, files ? 1 : 0);
	else if (dirs || files)
		basic_outp(&ops, dirs,
				(pos.y + 1 < argc - 1) ? 1 : 0, files ? 1 : 0);
	ft_lstdel(&dirs, delentry);
	ft_lstdel(&files, delentry);
	return (0);
}
