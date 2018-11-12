/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 08:17:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/12 15:50:03 by oevtushe         ###   ########.fr       */
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
	long long int	total;
	t_list			*data;
	struct stat		buf;
	char			*tmp1;

	total = 0;
	data = NULL;
	tmp1 = ft_strjoin(cur_path, "/");
	while ((runner = readdir(dir)))
	{
		full_path = ft_strjoin(tmp1, runner->d_name);
		if (lstat(full_path, &buf))
		{
			perror(NULL);
			exit(100);
		}
		if (ops->l && (runner->d_name[0] != '.' || ops->a))
		{
			total += buf.st_blocks;
			ft_lstadd(&data, ft_lstnew(runner->d_name, ft_strlen(runner->d_name) + 1));
		}
		else if (ops->a)
			ft_lstadd(&data, ft_lstnew(runner->d_name, ft_strlen(runner->d_name) + 1));
		else if (runner->d_name[0] != '.')
			ft_lstadd(&data, ft_lstnew(runner->d_name, ft_strlen(runner->d_name) + 1));
		free(full_path);
	}
	if (ops->l && data)
		printf("total %lld\n", total);
	ft_qslist(&data, cmp_strs);
	while (data)
	{
		full_path = ft_strjoin(tmp1, (char *)data->content);
		if (ops->l)
			handle_l(full_path, (char *)data->content);
		else if (ops->a)
			printf("%s\n", (char *)data->content);
		else
			printf("%s\n", (char *)data->content);
		free(full_path);
		data = data->next;
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
	else if (option == 'l')
	{
		p->l = 1;
		return (1);
	}
	return (0);
}

void	some_random_name(char *path, t_options *ops)
{
	DIR		*dir;
	char	*tmp1;
	char	*tmp2;

	if ((dir = opendir(path)))
	{
		print_dir(dir, ops, path);
		if (dir)
			closedir(dir);
	}
	else
	{
		if ((tmp2 = ft_strrchr(path, '/')))
			tmp1 = ft_strjoin("ft_ls: ", tmp2 + 1);
		else
			tmp1 = ft_strjoin("ft_ls: ", path);
		perror(tmp1);
		free(tmp1);
	}
}

void	list_it(t_options *ops, t_list *dirs, int fl_not_empty)
{
	int		fst;

	fst = 1;
	while (dirs)
	{
		if (fl_not_empty && fst)
		{
			printf("%s:\n", (char *)dirs->content);
			fst = 0;
		}
		else if (fl_not_empty)
			printf("\n%s:\n", (char *)dirs->content);
		some_random_name((char *)dirs->content, ops);
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
	size_t	len;
	char	*tmp;
	int	i;

	i = 0;
	while (i < argc)
	{
		if (!ft_get_fs_type(argv[i]))
		{
			tmp = ft_format("ft_ls: %s: No such file or directory\n", &len, argv[i]);
			ft_putstr_fd(tmp, 2);
			free(tmp);
		}
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

int	cmp_strs(void *a, void *b)
{
	char *fst;
	char *scd;

	fst = (char *)a;
	scd = (char *)b;
	return (ft_strcmp(fst, scd));
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
	ft_qslist(&files, cmp_strs);
	print_files(files, &ops);
	if (dirs && dirs->next)
		ft_qslist(&dirs, cmp_strs);
	if (ops.ur)
		big_r(dirs, &ops);
	else
		list_it(&ops, dirs, (pos.y + 1 < argc - 1) ? 1 : 0);
	ft_lstdel(&dirs, ft_delbasic);
	ft_lstdel(&files, ft_delbasic);
	return (0);
}
