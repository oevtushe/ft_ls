/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:39:13 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/12 16:38:41 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	inorder_tree_traversal(t_tree *level, t_options *ops, int p)
{
	while (level)
	{
		if (!p)
			printf("\n%s:\n", (char *)level->content);
		some_random_name((char *)level->content, ops);
		inorder_tree_traversal(level->kids, ops, 0);
		level = level->siblings;
	}
}

static void	build_tree(t_options *ops, t_tree *level)
{
	DIR				*dir;
	char			*new_path;
	struct dirent	*runner;

	while (level)
	{
		if ((dir = opendir((char *)level->content)))
		{
			while ((runner = readdir(dir)))
			{
				if (runner->d_type == DT_DIR && (runner->d_name[0] != '.' ||
							(ops->a && runner->d_namlen > 1 && runner->d_name[1] != '.')))
				{
					printf("Found new path: %s\n", runner->d_name);
					if (ft_strlen((char *)level->content) == 1 && ((char *)level->content)[0] == '/')
						new_path = ft_strjoin((char *)level->content, "");
					else
						new_path = ft_strjoin((char *)level->content, "/");
					ft_strconnect(&new_path, runner->d_name, 1);
					ft_treeadd_kid(&level,
							ft_treenew(new_path, ft_strlen(new_path) + 1));
					ft_strdel(&new_path);
				}
			}
			if (dir)
				closedir(dir);
		}
		ft_qstreelevel(&level->kids, cmp_strs);
		build_tree(ops, level->kids);
		level = level->siblings;
	}
}

void	big_r(t_list *dirs, t_options *ops)
{
	int		one_time;
	t_tree	*tree;

	one_time = 1;
	if (dirs && dirs->next)
		printf("%s:\n", (char *)dirs->content);
	while (dirs)
	{
		tree = ft_treenew(dirs->content, ft_strlen((char *)dirs->content) + 1);
		build_tree(ops, tree);
		inorder_tree_traversal(tree, ops, one_time);
		dirs = dirs->next;
		one_time = 0;
	}
}
