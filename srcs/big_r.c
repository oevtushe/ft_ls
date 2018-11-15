/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_r.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:39:13 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/13 21:27:39 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	inorder_tree_traversal(t_tree *level, t_options *ops, int first_time)
{
	t_entry *ent;

	while (level)
	{
		ent = (t_entry *)level->content;
		if (!first_time)
			printf("\n%s:\n", ent->full_path);
		print_dir(ent->full_path, ops);
		inorder_tree_traversal(level->kids, ops, 0);
		level = level->siblings;
	}
}

static void	sort_tree_level(t_options *ops, t_tree **level)
{
	if (ops->r && ops->t)
		ft_qstreelevel(level, cmp_rentries_t);
	else if (ops->r)
		ft_qstreelevel(level, cmp_rentries);
	else if (ops->t)
		ft_qstreelevel(level, cmp_entries_t);
	else
		ft_qstreelevel(level, cmp_entries);
}

static void	build_tree(t_options *ops, t_tree *level)
{
	DIR				*dir;
	char			*new_path;
	struct dirent	*runner;
	t_entry			*ent;

	while (level)
	{
		ent = (t_entry *)level->content;
		if ((dir = opendir(ent->full_path)))
		{
			while ((runner = readdir(dir)))
			{
				if (runner->d_type == DT_DIR && (runner->d_name[0] != '.' ||
							(ops->a && runner->d_namlen > 1 && runner->d_name[1] != '.')))
				{
					if (ft_strlen(ent->name) == 1 && (ent->name[0] == '/'))
						new_path = ft_strjoin(ent->full_path, "");
					else
						new_path = ft_strjoin(ent->full_path, "/");
					ft_strconnect(&new_path, runner->d_name, 1);
					ft_treeadd_kid(&level,
							ft_treenew_cc(ft_entrynew(runner->d_name,
									new_path), sizeof(t_entry)));
					ft_strdel(&new_path);
				}
			}
			if (dir)
				closedir(dir);
		}
		sort_tree_level(ops, &level->kids);
		build_tree(ops, level->kids);
		level = level->siblings;
	}
}

void	big_r(t_list *dirs, t_options *ops, int files_not_empty)
{
	int		one_time;
	t_tree	*tree;
	t_entry	*ent;

	one_time = 1;
	ent = (t_entry *)dirs->content;
	if (files_not_empty && dirs)
		printf("\n%s:\n", ent->full_path);
	else if (dirs && dirs->next)
		printf("%s:\n", ent->full_path);
	while (dirs)
	{
		tree = ft_treenew(dirs->content, sizeof(t_entry));
		build_tree(ops, tree);
		inorder_tree_traversal(tree, ops, one_time);
		dirs = dirs->next;
		one_time = 0;
	}
}
