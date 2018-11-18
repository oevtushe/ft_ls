/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:21:10 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/18 14:16:07 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>
# include <errno.h>
# include "ft_printf.h"
# include "libft.h"

typedef struct			s_ar
{
	int					argc;
	char				**argv;
}						t_ar;

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
	char				*full_path;
	char				*name;
}						t_entry;

void					handle_l(char *full_path, char *entry);
void					big_r(t_list *dirs, t_options *ops,
							int files_not_empty);
void					sort_list(t_options *ops, t_list **data);
void					print_dir(char *path, t_options *ops);
void					print_files(t_list *files, t_options *ops);
int						cmp_entries(void *a, void *b);
int						cmp_rentries(void *a, void *b);
int						cmp_entries_t(void *a, void *b);
int						cmp_rentries_t(void *a, void *b);

t_entry					*entrynew(char *name, char *full_path);
void					delentry(void *content, size_t content_size);
void					init_rights(struct stat *buf, char *rights, char *path);
int						set_option(void *container, char option);
void					*dup_content(void *content);
void					delentry(void *content, size_t content_size);
#endif
