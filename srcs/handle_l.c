/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:51:25 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/17 21:20:22 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <grp.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <sys/xattr.h>
#include <stdlib.h>
#include "ft_ls.h"

static void	init_rights(struct stat *buf, char *rights, char *path)
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

static char	*build_mtime(struct stat *buf)
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

static char	*make_entry(char *path, char *entry, int size)
{
	char	*tmp1;
	char	*res;

	tmp1 = ft_strnew(size);
	if (readlink(path, tmp1, size) == -1)
	{
		perror(NULL);
		exit(45);
	}
	res = ft_strjoin(entry, " -> ");
	ft_strconnect(&res, tmp1, 1);
	free(tmp1);
	return (res);
}

//void	handle_char

void	handle_l(char *full_path, char *entry)
{
	char			rights[12];
	struct stat		buf;
	struct group	*gr;
	struct passwd	*ps;
	char			*ct;
	char			*tmp1;
	char			*tmp2;
	char			*tmp3;

	rights[11] = 0;
	if (!lstat(full_path, &buf) && (ps = getpwuid(buf.st_uid)))
	{
		init_rights(&buf, rights, full_path);
		ct = build_mtime(&buf);
		if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
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
			tmp3 = make_entry(full_path, entry, buf.st_size);
			printf("%s\n", tmp3);
			free(tmp3);
		}
		else
			printf("%s\n", entry);
		free(ct);
		free(tmp1);
	}
	else
		perror(NULL);
}
