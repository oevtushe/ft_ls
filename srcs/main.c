/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 08:17:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/10 11:28:07 by oevtushe         ###   ########.fr       */
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

void	print_dir(DIR *dir, t_options *ops, char *cur_path)
{
	char			*full_path;
	struct dirent	*runner;
	struct stat		buf;
	long long int	total;

	total = 0;
	while ((runner = readdir(dir)))
	{
		if (lstat(cur_path, &buf))
			printf("Something went wrong\n");
		/*
		if (ops->a)
			printf("%s\n", runner->d_name);
			*/
		/*
		else if (runner->d_name[0] != '.')
			printf("%s\n", runner->d_name);
			*/
		if (ops->l && (runner->d_name[0] != '.' || ops->a))
		{
			full_path = ft_strjoin(cur_path, "/");
			ft_strconnect(&full_path, runner->d_name, 1);
			total += handle_l(full_path, runner->d_name);
			free(full_path);
		}
	}
	printf("total %lld\n", total);
}


int		set_option(void *container, char option)
{
	t_options *p;

	p = (t_options *)container;
	if (option == 'a')
	{
		p->a = 1;
		return (1);
	}
	else if (option == 'R')
	{
		p->ur = 1;
		return (1);
	}
	else if (option == 'l')
	{
		p->l = 1;
		return (1);
	}
	return (0);
}

void	list_it(t_options *ops, t_list *dirs, int fl_not_empty)
{
	DIR	*dir;
	int	pit;

	pit = (fl_not_empty || (dirs && dirs->next)) ? 1 : 0;
	while (dirs)
	{
		if ((dir = opendir((char *)dirs->content)))
		{
			if (pit)
				printf("%s:\n", (char *)dirs->content);
			print_dir(dir, ops, (char *)dirs->content);
			if (dir)
				closedir(dir);
		}
		else
		{
			printf("CAN'T OPEN !\n");
			exit(100); ///////////
		}
		printf("\n");
		dirs = dirs->next;
	}
}

void	init_files(t_list **files, int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (ft_get_fs_type(argv[i]) == 2)
			ft_lstadd(files, ft_lstnew(argv[i], ft_strlen(argv[i]) + 1));
		++i;
	}
}

void	init_dirs(t_list **dirs, int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (ft_get_fs_type(argv[i]) == 1)
			ft_lstadd(dirs, ft_lstnew(argv[i], ft_strlen(argv[i]) + 1));
		++i;
	}
}

void	check_for_garbage(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_get_fs_type(argv[i]))
			printf("ft_ls: %s: No such file or directory\n", argv[i]);
		++i;
	}
}

void	print_files(t_list *files, t_options *ops)
{
	while (files)
	{
		if (ops->l)
			handle_l((char *)files->content, (char *)files->content);
		else
			printf("%s\n", (char *)files->content);
		files = files->next;
	}
}

void	ft_delbasic(void *content, size_t content_size)
{
	content_size = 0;
	free(content);
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
		ft_lstadd(&dirs, ft_lstnew(".", 2));
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
	init_files(&files, argc - pos.y - 1, &argv[pos.y + 1]);
	init_dirs(&dirs, argc - pos.y - 1, &argv[pos.y + 1]);
	check_for_garbage(argc - pos.y - 1, &argv[pos.y + 1]);
	print_files(files, &ops);
	// Do something with files
	if (ops.ur)
		big_r(dirs, &ops);
	else
		list_it(&ops, dirs, (files && files->next) ? 1 : 0);
	ft_lstdel(&dirs, ft_delbasic);
	ft_lstdel(&files, ft_delbasic);
	return (0);
}
