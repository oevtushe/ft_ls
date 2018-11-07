/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:21:10 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/07 10:51:56 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <errno.h>
# include <stdio.h> //
# include <dirent.h>
# include "libft.h"

typedef struct			s_tree
{
	void				*content;
	size_t				content_size;
	struct s_tree		*siblings;
	struct s_tree		*kids;
}						t_tree;

typedef struct			s_options
{
	int					a;
	int					ur;
}						t_options;

void		big_r(t_list *dirs, t_options *ops);
void		print_dir(DIR *dir, t_options *ops);
int			ft_get_fs_type(char *str);

void		ft_treeadd_kid(t_tree **tree, t_tree *new);
t_tree		*ft_treenew(void *content, size_t content_size);
int			ft_isdir(char *str);
int			ft_isfile(char *str);

#endif
