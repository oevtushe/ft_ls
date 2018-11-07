/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:39:13 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/07 10:50:38 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_data(t_tree *tree, t_options *ops)
{
	DIR *dir;

	printf("\ntry to open %s\n", (char *)tree->content);
	if ((dir = opendir((char *)tree->content)))
	{
		printf("opened %s\n", (char *)tree->content);
		print_dir(dir, ops);
		closedir(dir);
		printf("closed %s\n", (char *)tree->content);
	}
	else
		printf("CAN'T OPEN %s\n", (char *)tree->content);
}

static void	inorder_tree_traversal(t_tree *level, t_options *ops)
{
	while (level)
	{
		print_data(level, ops);
		inorder_tree_traversal(level->kids, ops);
		level = level->siblings;
	}
}

static void	build_tree(t_options *ops, t_tree *level)
{
	DIR				*dir;
	int				i;
	char			*new_path;
	struct dirent	*runner;

	i = 0;
	while (level)
	{
		//printf("try to open %s\n", (char *)level->content);
		if ((dir = opendir((char *)level->content)))
		{
			//printf("opened %s\n", (char *)level->content);

			// DANGEROUS
			runner = readdir(dir);
			runner = readdir(dir);
			while ((runner = readdir(dir)))
			{
				if (runner->d_type == DT_DIR)
				{
					new_path = ft_strjoin((char *)level->content, "/");
					ft_strconnect(&new_path, runner->d_name, 1);
					//printf("find new_path: %s\n", new_path);
					ft_treeadd_kid(&level,
							ft_treenew(new_path, ft_strlen(new_path) + 1));
					ft_strdel(&new_path);
				}
			}
			if (dir)
			{
				//printf("closed %s\n", (char *)level->content);
				closedir(dir);
			}
		}
		else
		{
			//printf("CAN'T OPEN %s\n", (char *)level->content);
			//exit(100); ///////////
		}
		build_tree(ops, level->kids);
		level = level->siblings;
	}
	//printf("\n");
	++i;
}

void	big_r(t_list *dirs, t_options *ops)
{
	t_tree	*tree;

	while (dirs)
	{
		tree = ft_treenew(dirs->content, ft_strlen((char *)dirs->content));
		build_tree(ops, tree);
		inorder_tree_traversal(tree, ops);
		dirs = dirs->next;
	}
}
