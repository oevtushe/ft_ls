/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 19:02:49 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/13 21:35:33 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include <stdlib.h>
#include "ft_ls.h"

static void	print_dir_hlp(DIR *dir, t_options *ops, char *cur_path)
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
		if (ops->l && (ops->a || runner->d_name[0] != '.'))
			total += buf.st_blocks;
		if (ops->a || runner->d_name[0] != '.')
			ft_lstadd(&data, ft_lstnew_cc(ft_entrynew(
							runner->d_name, full_path), sizeof(t_entry)));
		free(full_path);
	}
	if (ops->l && data)
		printf("total %lld\n", total);
	sort_list(ops, &data);
	while (data)
	{
		if (ops->l)
			handle_l(((t_entry *)data->content)->full_path, ((t_entry *)data->content)->name);
		else
			printf("%s\n", ((t_entry *)data->content)->name);
		data = data->next;
	}
	free(tmp1);
}

void		print_dir(char *path, t_options *ops)
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

void	print_files(t_list *files, t_options *ops)
{
	t_entry *cur;

	while (files)
	{
		cur = (t_entry *)files->content;
		if (ops->l)
			handle_l(cur->full_path, cur->full_path);
		else
			printf("%s\n", cur->full_path);
		files = files->next;
	}
}
