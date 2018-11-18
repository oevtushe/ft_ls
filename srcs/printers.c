/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:02:49 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/18 14:12:17 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdlib.h>
#include "ft_ls.h"

static t_list	*mk_list(DIR *dir, long long int *total,
		char *cur_path, t_options *ops)
{
	t_list			*data;
	char			*tmp1;
	char			*full_path;
	struct dirent	*runner;
	struct stat		buf;

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
		if (ops->l && (ops->a || runner->d_name[0] != '.'))
			*total += buf.st_blocks;
		if (ops->a || runner->d_name[0] != '.')
			ft_lstadd(&data, ft_lstnew_cc(entrynew(
							runner->d_name, full_path), sizeof(t_entry)));
		free(full_path);
	}
	free(tmp1);
	return (data);
}

static void		print_dir_hlp(DIR *dir, t_options *ops, char *cur_path)
{
	long long int	total;
	t_list			*data;
	t_list			*tmp2;

	total = 0;
	data = mk_list(dir, &total, cur_path, ops);
	if (ops->l && data)
		ft_printf("total %lld\n", total);
	sort_list(ops, &data);
	tmp2 = data;
	while (data)
	{
		if (ops->l)
			handle_l(((t_entry *)data->content)->full_path,
				((t_entry *)data->content)->name);
		else
			ft_printf("%s\n", ((t_entry *)data->content)->name);
		data = data->next;
	}
	ft_lstdel(&tmp2, delentry);
}

void			print_dir(char *path, t_options *ops)
{
	DIR		*dir;
	char	*tmp1;
	char	*tmp2;

	if ((dir = opendir(path)))
	{
		print_dir_hlp(dir, ops, path);
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

void			print_files(t_list *files, t_options *ops)
{
	t_entry *cur;

	while (files)
	{
		cur = (t_entry *)files->content;
		if (ops->l)
			handle_l(cur->full_path, cur->full_path);
		else
			ft_printf("%s\n", cur->full_path);
		files = files->next;
	}
}
