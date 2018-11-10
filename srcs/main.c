/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 08:17:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/10 10:40:36 by oevtushe         ###   ########.fr       */
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
#include <sys/xattr.h>
#include "ft_ls.h"

void	init_rights(struct stat *buf, char *rights, char *path)
{
	if (S_ISDIR(buf->st_mode))
		rights[0] = 'd';
	else if (S_ISLNK(buf->st_mode))
		rights[0] = 'l';
	else if (S_ISFIFO(buf->st_mode))
		rights[0] = 'p';
	else if (S_ISBLK(buf->st_mode))
		rights[0] = 'b';
	else if (S_ISCHR(buf->st_mode))
		rights[0] = 'c';
	else if (S_ISSOCK(buf->st_mode))
		rights[0] = 's';
	else
		rights[0] = '-';
	if (buf->st_mode & S_IRUSR)
		rights[1] = 'r';
	else
		rights[1] = '-';
	if (buf->st_mode & S_IWUSR)
		rights[2] = 'w';
	else
		rights[2] = '-';
	if ((buf->st_mode & S_ISUID) && (buf->st_mode & S_IXUSR))
		rights[3] = 's';
	else if (buf->st_mode & S_ISUID)
		rights[3] = 'S';
	else if (buf->st_mode & S_IXUSR)
		rights[3] = 'x';
	else
		rights[3] = '-';
	////////////////////////////////
	if (buf->st_mode & S_IRGRP)
		rights[4] = 'r';
	else
		rights[4] = '-';
	if (buf->st_mode & S_IWGRP)
		rights[5] = 'w';
	else
		rights[5] = '-';
	if ((buf->st_mode & S_ISGID) && (buf->st_mode & S_IXGRP))
		rights[6] = 's';
	else if (buf->st_mode & S_ISGID)
		rights[6] = 'S';
	else if (buf->st_mode & S_IXGRP)
		rights[6] = 'x';
	else
		rights[6] = '-';
	////////////////////////////////
	if (buf->st_mode & S_IROTH)
		rights[7] = 'r';
	else
		rights[7] = '-';
	if (buf->st_mode & S_IWOTH)
		rights[8] = 'w';
	else
		rights[8] = '-';
	if ((buf->st_mode & S_ISVTX) && (buf->st_mode & S_IXOTH))
		rights[9] = 't';
	else if (buf->st_mode & S_ISVTX)
		rights[9] = 'T';
	else if (buf->st_mode & S_IXOTH)
		rights[9] = 'x';
	else
		rights[9] = '-';
	if (listxattr(path, NULL, 0, XATTR_NOFOLLOW) > 0)
		rights[10] = '@';
	else
		rights[10] = ' ';
}

int		ft_abs(int a)
{
	return (a >= 0 ? a : -a);
}

char	*build_mtime(struct stat *buf)
{
	char *ct;
	char *tmp1;
	char *tmp2;

	ct = ctime(&buf->st_mtimespec.tv_sec);
	// 15552000 -> 6 months in seconds
	if (ft_abs(buf->st_mtimespec.tv_sec - time(NULL)) > 15552000)
	{
		tmp1 = ft_strsub(ct, 4, 7);
		tmp2 = ft_strsub(ct, 20, 4);
		ft_strconnect(&tmp1, tmp2, 1);
		free(tmp2);
	}
	else
		tmp1 = ft_strsub(ct, 4, 12);
	return (tmp1);
}

char	*make_entry(char *path, char *entry)
{
	char	*tmp1;
	char	*res;

	tmp1 = ft_strnew(PATH_MAX);
	if (readlink(path, tmp1, PATH_MAX) == -1)
	{
		perror(NULL);
		exit(45);
	}
	res = ft_strjoin(entry, " -> ");
	ft_strconnect(&res, tmp1, 1);
	return (res);
}

long long int	handle_l(char *full_path, char *entry)
{
	char			rights[12];
	struct stat		buf;
	struct group	*gr;
	struct passwd	*ps;
	char			*ct;
	char			*tmp1;
	char			*tmp2;
	char			*tmp3;
	long long int	total;

	rights[11] = 0;
	total = 0;
	if (!lstat(full_path, &buf) && (ps = getpwuid(buf.st_uid)))
	{
		init_rights(&buf, rights, full_path);
		ct = build_mtime(&buf);
		if (S_ISCHR(buf.st_mode))
		{
			tmp1 = ft_uitoabase_gen(major(buf.st_rdev), 0, 10);
			ft_strconnect(&tmp1, ", ", 1);
			tmp2 = ft_uitoabase_gen(minor(buf.st_rdev), 0, 10);
			ft_strconnect(&tmp1, tmp2, 1);
			free(tmp2);
		}
		else
			tmp1 = ft_uitoabase_gen(buf.st_size, 0, 10);
		if ((gr = getgrgid(buf.st_gid)))
			printf("%s %d %s %s %s %s ", rights, buf.st_nlink,
					ps->pw_name, gr->gr_name, tmp1, ct);
		else
			printf("%s %d %s %u %s %s ", rights, buf.st_nlink,
					ps->pw_name, buf.st_gid, tmp1, ct);
		if (S_ISLNK(buf.st_mode))
		{
			tmp3 = make_entry(full_path, entry);
			printf("%s\n", tmp3);
			free(tmp3);
		}
		else
			printf("%s\n", entry);
		free(ct);
		free(tmp1);
		total = buf.st_blocks;
	}
	else
	{
		perror(NULL);
		exit(42);
	}
	return (total);
}

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
		if (ops->l)
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

void	list_it(t_options *ops, t_list *dirs)
{
	DIR	*dir;

	while (dirs)
	{
		if ((dir = opendir((char *)dirs->content)))
		{
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
