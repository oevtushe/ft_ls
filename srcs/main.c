/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 08:17:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/07 11:15:05 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h> //
#include <errno.h>
#include <stdlib.h>
#include "ft_ls.h"

void	print_dir(DIR *dir, t_options *ops)
{
	struct dirent	*runner;

	while ((runner = readdir(dir)))
	{
		if (ops->a)
			printf("%s\n", runner->d_name);
		else if (runner->d_name[0] != '.')
			printf("%s\n", runner->d_name);
	}
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
	return (0);
}

void	list_it(t_options *ops, t_list *dirs)
{
	DIR	*dir;

	while (dirs)
	{
		if ((dir = opendir((char *)dirs->content)))
		{
			printf("%s:\n", (char *)dirs->content);
			print_dir(dir, ops);
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
		if (ft_isfile(argv[i]))
			ft_lstadd(files, ft_lstnew(argv[i], ft_strlen(argv[i])));
		++i;
	}
}

void	init_dirs(t_list **dirs, int argc, char **argv)
{
	int i;

	i = 0;
	while (i < argc)
	{
		if (ft_isdir(argv[i]))
			ft_lstadd(dirs, ft_lstnew(argv[i], ft_strlen(argv[i])));
		++i;
	}
}

void	check_for_garbage(int argc, char **argv)
{
	int	i;

	i = 0;
	while (i < argc)
	{
		if (ft_get_fs_type(argv[i]) == 2)
			printf("ft_ls: %s: No such file or directory\n", argv[i]);
		++i;
	}
}

void	print_files(t_list *files)
{
	while (files)
	{
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
	int				pos;
	int				vld;
	t_list			*files;
	t_list			*dirs;

	vld = argc - 1;
	files = NULL;
	dirs = NULL;
	ft_bzero((void *)&ops, sizeof(t_options));
	pos = ft_argsparser_ti(&argv[1], &vld, (void*)&ops, set_option);
	if (vld == 1 || ((pos >= argc - 1) && vld == 3))
		ft_lstadd(&dirs, ft_lstnew(".", 2));
	else if (vld == 0)
	{
		if (vld == 0)
		{
			printf("ft_ls: illegal option -- %c\n", argv[pos + 1][1]);
			return (42);
		}
		else
		{
			tmp = ft_strjoin("ft_ls: ", argv[pos + 1]);
			perror(tmp);
			free(tmp);
			return (43);
		}
	}
	init_files(&files, argc - pos - 1, &argv[pos + 1]);
	init_dirs(&dirs, argc - pos - 1, &argv[pos + 1]);
	check_for_garbage(argc - pos - 1, &argv[pos + 1]);
	print_files(files);
	// Do something with files
	if (ops.ur)
		big_r(dirs, &ops);
	else
		list_it(&ops, dirs);
	ft_lstdel(&dirs, ft_delbasic);
	ft_lstdel(&files, ft_delbasic);
	return (0);
}
