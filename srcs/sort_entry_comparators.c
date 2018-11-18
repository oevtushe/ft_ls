/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_entry_comparators.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:53:15 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/18 14:13:33 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdlib.h>
#include "ft_ls.h"

int	cmp_entries(void *a, void *b)
{
	t_entry *fst;
	t_entry *scd;

	fst = (t_entry *)a;
	scd = (t_entry *)b;
	return (ft_strcmp(fst->name, scd->name));
}

int	cmp_rentries(void *a, void *b)
{
	t_entry *fst;
	t_entry *scd;

	fst = (t_entry *)a;
	scd = (t_entry *)b;
	return (ft_strcmp(scd->name, fst->name));
}

int	cmp_entries_t(void *a, void *b)
{
	t_entry		*fst;
	t_entry		*scd;
	struct stat	buf1;
	struct stat	buf2;

	fst = (t_entry *)a;
	scd = (t_entry *)b;
	if (lstat(fst->full_path, &buf1))
		exit(22);
	if (lstat(scd->full_path, &buf2))
		exit(33);
	if (buf1.st_mtimespec.tv_sec < buf2.st_mtimespec.tv_sec)
		return (1);
	else if (buf1.st_mtimespec.tv_sec > buf2.st_mtimespec.tv_sec)
		return (-1);
	else
		return (ft_strcmp(fst->name, scd->name));
}

int	cmp_rentries_t(void *a, void *b)
{
	t_entry		*fst;
	t_entry		*scd;
	struct stat	buf1;
	struct stat	buf2;

	fst = (t_entry *)a;
	scd = (t_entry *)b;
	if (lstat(fst->full_path, &buf1))
		exit(22);
	if (lstat(scd->full_path, &buf2))
		exit(33);
	if (buf1.st_mtimespec.tv_sec > buf2.st_mtimespec.tv_sec)
		return (1);
	else if (buf1.st_mtimespec.tv_sec < buf2.st_mtimespec.tv_sec)
		return (-1);
	else
		return (ft_strcmp(scd->name, fst->name));
}
