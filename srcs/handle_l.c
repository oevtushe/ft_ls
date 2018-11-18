/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_l.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 10:51:25 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/18 15:09:30 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <sys/stat.h>
#include <grp.h>
#include <unistd.h>
#include <pwd.h>
#include <time.h>
#include <sys/xattr.h>
#include <stdlib.h>
#include "ft_ls.h"

/*
** 15552000 -> 6 months in seconds
*/

static char	*build_mtime(struct stat *buf)
{
	char *ct;
	char *tmp1;
	char *tmp2;

	ct = ctime(&buf->st_mtimespec.tv_sec);
	if (ft_abs(time(NULL) - buf->st_mtimespec.tv_sec) > 15552000)
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

static char	*handle_block_char_dev(struct stat *buf)
{
	char *tmp1;
	char *tmp2;

	tmp1 = ft_uitoabase_gen(major(buf->st_rdev), 0, 10);
	ft_strconnect(&tmp1, ", ", 1);
	tmp2 = ft_uitoabase_gen(minor(buf->st_rdev), 0, 10);
	ft_strconnect(&tmp1, tmp2, 1);
	free(tmp2);
	return (tmp1);
}

static void	help2(struct stat *buf, struct passwd *ps, char *tmp1, char *rights)
{
	struct group	*gr;
	char			*ct;

	ct = build_mtime(buf);
	if ((gr = getgrgid(buf->st_gid)))
		ft_printf("%s %d %s %s %s %s ", rights, buf->st_nlink,
				ps->pw_name, gr->gr_name, tmp1, ct);
	else
		ft_printf("%s %d %s %u %s %s ", rights, buf->st_nlink,
				ps->pw_name, buf->st_gid, tmp1, ct);
	free(ct);
}

static void	handle_link(char *full_path, char *entry, struct stat *buf)
{
	char	*tmp1;
	char	*res;

	tmp1 = ft_strnew(buf->st_size);
	if (readlink(full_path, tmp1, buf->st_size) == -1)
	{
		perror(NULL);
		exit(45);
	}
	res = ft_strjoin(entry, " -> ");
	ft_strconnect(&res, tmp1, 1);
	ft_printf("%s\n", res);
	free(tmp1);
	free(res);
}

void		handle_l(char *full_path, char *entry)
{
	char			rights[12];
	struct stat		buf;
	struct passwd	*ps;
	char			*tmp1;

	rights[11] = 0;
	if (!lstat(full_path, &buf) && (ps = getpwuid(buf.st_uid)))
	{
		init_rights(&buf, rights, full_path);
		if (S_ISCHR(buf.st_mode) || S_ISBLK(buf.st_mode))
			tmp1 = handle_block_char_dev(&buf);
		else
			tmp1 = ft_uitoabase_gen(buf.st_size, 0, 10);
		help2(&buf, ps, tmp1, rights);
		if (S_ISLNK(buf.st_mode))
			handle_link(full_path, entry, &buf);
		else
			ft_printf("%s\n", entry);
		free(tmp1);
	}
	else
		perror(NULL);
}
