/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 08:17:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/18 14:08:47 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_ls.h"

static void	basic_outp(t_options *ops, t_list *dirs,
		int fl_not_empty, int files_not_empty)
{
	if (dirs && files_not_empty)
		ft_printf("\n%s:\n", ((t_entry *)dirs->content)->full_path);
	else if (dirs && fl_not_empty)
		ft_printf("%s:\n", ((t_entry *)dirs->content)->full_path);
	while (dirs)
	{
		print_dir(((t_entry *)dirs->content)->full_path, ops);
		dirs = dirs->next;
		if (fl_not_empty && dirs)
			ft_printf("\n%s:\n", ((t_entry *)dirs->content)->full_path);
	}
}

static void	init_lists(t_list **dirs, t_list **files,
		t_ar ar, t_options *ops)
{
	int			i;
	mode_t		mode;
	struct stat buf;

	i = -1;
	while (++i < ar.argc)
	{
		if (!lstat(ar.argv[i], &buf))
		{
			mode = buf.st_mode;
			if (S_ISDIR(mode) || (S_ISLNK(mode) && !ops->l))
				ft_lstadd(dirs, ft_lstnew_cc(
							entrynew(ar.argv[i], ar.argv[i]), sizeof(t_entry)));
			else
				ft_lstadd(files, ft_lstnew_cc(
							entrynew(ar.argv[i], ar.argv[i]), sizeof(t_entry)));
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
			tmp = ft_format("ft_ls: %s: No such file or directory\n",
					&len, argv[i]);
			ft_putstr_fd(tmp, 2);
			free(tmp);
		}
		++i;
	}
}

static int	parse_args(int argc, char **argv, t_options *ops, t_pos *pos)
{
	int			vld;
	char		*tmp;
	size_t		sz;

	vld = argc - 1;
	ft_bzero(ops, sizeof(t_options));
	*pos = ft_argsparser_ti(&argv[1], &vld, (void*)ops, set_option);
	if (vld == 0)
	{
		if (vld == 0)
		{
			tmp = ft_format("ft_ls: illegal option -- %c\n", &sz,
					argv[pos->y + 1][pos->x]);
			ft_putstr_fd(tmp, 2);
			exit(42);
		}
		else
		{
			tmp = ft_strjoin("ft_ls: ", argv[pos->y + 1]);
			perror(tmp);
			free(tmp);
			exit(43);
		}
	}
	return (vld);
}

int			main(int argc, char **argv)
{
	t_options		ops;
	t_pos			pos;
	int				vld;
	t_list			*files;
	t_list			*dirs;

	dirs = NULL;
	files = NULL;
	vld = parse_args(argc, argv, &ops, &pos);
	if (vld == 1 || ((pos.y >= argc - 1) && vld == 3))
		ft_lstadd(&dirs, ft_lstnew_cc(entrynew(".", "."), sizeof(t_entry)));
	init_lists(&dirs, &files, (t_ar){argc - pos.y - 1, &argv[pos.y + 1]}, &ops);
	if (files && files->next)
		sort_list(&ops, &files);
	if (dirs && dirs->next)
		sort_list(&ops, &dirs);
	check_for_garbage(argc - pos.y - 1, &argv[pos.y + 1]);
	print_files(files, &ops);
	if (ops.ur && dirs)
		big_r(dirs, &ops, files ? 1 : 0);
	else if (dirs || files)
		basic_outp(&ops, dirs, (pos.y + 1 < argc - 1) ? 1 : 0, files ? 1 : 0);
	ft_lstdel(&dirs, delentry);
	ft_lstdel(&files, delentry);
	return (0);
}
