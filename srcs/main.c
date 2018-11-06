/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 08:17:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/06 12:51:29 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h> //
#include <stdlib.h>
#include "ft_ls.h"

typedef struct		s_options
{
	int		a;
	int		ur;
}					t_options;

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
	return (0);
}

void	list_it(DIR *dir, t_options *ops, char **argv, int argc)
{
	int				i;
	struct dirent	*runner;

	i = 0;
	printf("extra args: %d\n", argc);
	while (i < argc)
	{
		if ((dir = opendir(argv[i])))
		{
			printf("%s:\n", argv[i]);
			while ((runner = readdir(dir)))
			{
				if (ops->a)
					printf("%s\n", runner->d_name);
				else if (runner->d_name[0] != '.')
					printf("%s\n", runner->d_name);
			}
			if (dir)
				closedir(dir);
		}
		else
		{
			printf("BAD !\n");
			exit(100); ///////////
		}
		printf("\n");
		++i;
	}
}

void	print_data(t_tree *tree)
{
	DIR *dir;
	struct dirent *runner;

	printf("\ntry to open %s\n", (char *)tree->content);
	if ((dir = opendir((char *)tree->content)))
	{
		printf("opened %s\n", (char *)tree->content);
		while ((runner = readdir(dir)))
			printf("%s\n", runner->d_name);
		if (dir)
		{
			printf("closed %s\n", (char *)tree->content);
			closedir(dir);
		}
	}
	else
		printf("CAN'T OPEN %s\n", (char *)tree->content);
}

void	inorder_tree_traversal(t_tree *level)
{
	while (level)
	{
		print_data(level);
		inorder_tree_traversal(level->kids);
		level = level->siblings;
	}
}

void	build_tree(DIR *dir, t_options *ops, t_tree *level)
{
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
			while ((runner = readdir(dir)))
			{
				if (runner->d_type == DT_DIR && runner->d_name[0] != '.')
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
		build_tree(dir, ops, level->kids);
		level = level->siblings;
	}
	//printf("\n");
	++i;
}

int		main(int argc, char **argv)
{
	DIR				*cur_dir;
	char			*tmp;
	t_options		ops;
	int				pos;
	int				vld;

	vld = argc - 1;
	cur_dir = NULL;
	ft_bzero((void *)&ops, sizeof(t_options));
	pos = ft_argsparser_ti(&argv[1], &vld, (void*)&ops, set_option);
	printf("vld = %d\n", vld);
	if (vld == 1 || ((pos >= argc - 1) && vld == 3))
	{
		printf("No dirs passed\n");
		cur_dir = opendir(".");
	}
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
	if (ops.ur)
	{
		t_tree *tree;

		while (++pos < argc)
		{
			tree = ft_treenew(argv[pos], ft_strlen(argv[pos]));
			build_tree(cur_dir, &ops, tree);
			inorder_tree_traversal(tree);
		}
	}
	else
		list_it(cur_dir, &ops, &argv[pos + 1], argc - pos - 1);
	return (0);
}
