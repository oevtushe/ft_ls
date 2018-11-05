/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 08:17:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/05 15:07:01 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <dirent.h>
#include <stdio.h> //
#include <stdlib.h>
#include "libft.h"

typedef struct		s_options
{
	int		a;
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
	return (0);
}

int		main(int argc, char **argv)
{
	DIR				*cur_dir;
	struct dirent	*runner;
	t_options		ops;
	int				pos;
	int				vld;

	vld = argc - 1;
	cur_dir = NULL;
	ft_bzero((void *)&ops, sizeof(t_options));
	pos = ft_argsparser_ti(&argv[1], &vld, (void*)&ops, set_option);
	if (pos < argc - 1 && (vld == 2 || vld == 3))
		cur_dir = opendir(argv[pos + 1]);
	else if (vld == 1 || vld == 3)
		cur_dir = opendir(".");
	if (cur_dir)
	{
		while ((runner = readdir(cur_dir)))
			printf("%s\n", runner->d_name);
		closedir(cur_dir);
	}
	else
	{
		char *tmp;

		if (vld == 0)
		{
			printf("ft_ls: illegal option -- %c\n", argv[pos + 1][1]);
			return (43);
		}
		tmp = ft_strjoin("ft_ls: ", argv[pos + 1]);
		perror(tmp);
		free(tmp);
	}
	return (0);
}
