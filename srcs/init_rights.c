/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_rights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:51:43 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/18 14:11:28 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/xattr.h>
#include <sys/stat.h>
#include "ft_ls.h"

static void	set_type(struct stat *buf, char *rights)
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
}

static void	set_user_rights(struct stat *buf, char *rights)
{
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
}

static void	set_group_rights(struct stat *buf, char *rights)
{
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
}

static void	set_other_rights(struct stat *buf, char *rights, char *path)
{
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

void		init_rights(struct stat *buf, char *rights, char *path)
{
	set_type(buf, rights);
	set_user_rights(buf, rights);
	set_group_rights(buf, rights);
	set_other_rights(buf, rights, path);
}
