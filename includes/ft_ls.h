/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:21:10 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/15 14:31:00 by oevtushe         ###   ########.fr       */
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
	int					r;
	int					t;
}						t_options;

typedef struct			s_entry
{
	char *full_path;
	char *name;
}						t_entry;

void		handle_l(char *full_path, char *entry);
void		big_r(t_list *dirs, t_options *ops, int files_not_empty);
void		sort_list(t_options *ops, t_list **data);
void		print_dir(char *path, t_options *ops);
void		print_files(t_list *files, t_options *ops);
int			cmp_entries(void *a, void *b);
int			cmp_rentries(void *a, void *b);
int			cmp_entries_t(void *a, void *b);
int			cmp_rentries_t(void *a, void *b);

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

t_entry		*ft_entrynew(char *name, char *full_path);
#endif
