/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:21:10 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/12 14:01:55 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <errno.h>
# include <stdio.h> //
# include <dirent.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct			s_tree
{
	void				*content;
	size_t				content_size;
	struct s_tree		*siblings;
	struct s_tree		*kids;
}						t_tree;

// bitfield ?
typedef struct			s_options
{
	int					a;
	int					ur;
	int					l;
}						t_options;

void		handle_l(char *full_path, char *entry);
void		big_r(t_list *dirs, t_options *ops);
void		print_dir(DIR *dir, t_options *ops, char *cur_path);
int			ft_get_fs_type(char *str);
int			ft_abs(int a);

void		ft_qstree_kids(t_tree **tree, int (*cmp)(void *, void *));
void		ft_treeadd_kid(t_tree **tree, t_tree *new);
t_tree		*ft_treenew(void *content, size_t content_size);
void		ft_qslist(t_list **lst, int (*cmp)(void *, void *));

t_tree		*ft_treenew_cc(void *content, size_t content_size);
void		ft_qstreelevel(t_tree **tree, int (*cmp)(void *, void *));
t_tree		*ft_arrtotreelevel(void **arr, int size);
void		**ft_treeleveltoarr(t_tree *tree);
void		ft_treeleveldel(t_tree **tree, void (*del)(void*, size_t));
size_t		ft_treelevellen(const t_tree *tree);


int			cmp_strs(void *a, void *b);
void		some_random_name(char *path, t_options *ops);

#endif
