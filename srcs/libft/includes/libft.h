/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 14:06:36 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/18 14:18:48 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _LIBFT_H
# define _LIBFT_H

# include <string.h>
# include <inttypes.h>
# include <limits.h>

# define ABS(x) (x) >= 0 ? (x) : -(x)
# define GNL_BUFF_SIZE 4096

typedef struct			s_tree
{
	void				*content;
	size_t				content_size;
	struct s_tree		*siblings;
	struct s_tree		*kids;
}						t_tree;

typedef struct			s_pos
{
	int	x;
	int	y;
}						t_pos;

typedef struct			s_stream
{
	int					fd;
	char				*buff;
}						t_stream;

typedef struct			s_pair
{
	void				*fst;
	void				*scd;
}						t_pair;

typedef struct			s_list
{
	void				*content;
	size_t				content_size;
	struct s_list		*next;
}						t_list;

typedef struct			s_list_de
{
	void				*content;
	size_t				content_size;
	struct s_list_de	*next;
	struct s_list_de	*prev;
}						t_list_de;

/*
** Memory
*/

void					ft_realloc(void **mem, size_t old_size,
							size_t new_size);
void					ft_bzero(void *s, size_t n);
void					*ft_memccpy(void *dst, const void *src,
							int c, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					*ft_memchr(const void *s, int c, size_t n);
void					*ft_memmove(void *dst, const void *src,
							size_t len);
void					*ft_memset(void *b, int c, size_t len);
int						ft_memcmp(const void *s1, const void *s2,
							size_t n);
void					*ft_memdup(void *data, size_t size);
void					*ft_memalloc(size_t size);
void					ft_memdel(void **ap);
void					ft_swap(void *p1, void *p2, size_t size);

/*
** Stings
*/

char					*ft_strdup(const char *s1);
size_t					ft_strlen(const char *s);
char					*ft_strdup(const char *s1);
char					*ft_strcpy(char *dst, const char *src);
char					*ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strcat(char *s1, const char *s2);
char					*ft_strncat(char *s1, const char *s2, size_t n);
size_t					ft_strlcat(char *dst, const char *src,
							size_t dstsize);
char					*ft_strchr(const char *s, int c);
char					*ft_strrchr(const char *s, int c);
void					ft_strconnect(char **str1, const char *str2,
							int side);
int						ft_strcmp(const char *s1, const char *s2);
int						ft_strncmp(const char *s1, const char *s2,\
							size_t n);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strnstr(const char *haystack,\
							const char *needle, size_t len);
int						ft_atoi(const char *str);
char					*ft_strnew(size_t size);
void					ft_strdel(char **as);
void					ft_strclr(char *s);
void					ft_striter(char *s, void (*f)(char*));
void					ft_striteri(char *s, void (*f)(unsigned int, char*));
char					*ft_strmap(char const *s, char (*f)(char));
char					*ft_strmapi(char const *s,
							char (*f)(unsigned int, char));
int						ft_strequ(char const *s1, char const *s2);
int						ft_strnequ(char const *s1, char const *s2,
							size_t n);
char					*ft_strsub(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s);
char					**ft_strsplit(char const *s, char c);
char					*ft_itoa(int n);
int						ft_strfnd(const char *s, char c);
char					*ft_itoabase(intmax_t val, unsigned int base);
char					*ft_uitoabase_gen(uintmax_t val, int sign,
							unsigned int base);
void					ft_str_realloc(char **str, size_t new_len);
void					ft_strconnect(char **str1, const char *str2, int side);
void					ft_strcntllr(char **str, size_t new_len, char filler,
							int side);
void					ft_strtoupper(char *str);
int						ft_isnumber(char *str);
int						ft_isvldint(char *str);
int						ft_count_words(const char *str);
int						ft_strchcnt(char *line, char c);

/*
** Other
*/

int						ft_abs(int a);
int						ft_isalpha(int c);
int						ft_isdigit(int c);
int						ft_isalnum(int c);
int						ft_isascii(int c);
int						ft_isprint(int c);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					ft_putchar(char c);
void					ft_putstr(char const *s);
void					ft_putendl(char const *s);
void					ft_putnbr(int n);
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char const *s, int fd);
void					ft_putendl_fd(char const *s, int fd);
void					ft_putnbr_fd(int n, int fd);
void					ft_putstr_ln(const char *str, size_t ln);
void					ft_spsign(intmax_t val, uintmax_t *uval, int *sign);
int						ft_intln(int n);
size_t					ft_parrlen_zt(void **arr);
void					ft_parrdel_zt(void ***arr);
int						get_next_line(const int fd, char **line);
void					ft_qsarr(void **arr, int start, int end,
							int (*cmp)(void *, void *));
void					ft_freepa_sd(void ***arr, int size);
void					ft_freepa(void ***arr, int size,
							void (*del)(void *content));
int						ft_argsparser(char **argv, int size, void *container,
							int (*set_option)(void *container, char option));
t_pos					ft_argsparser_ti(char **argv, int *sz_vld,
							void *container,
							int (*set_option)(void *container, char option));
void					ft_realloc(void **mem, size_t old_size,
							size_t new_size);

/*
** List
*/

void					**ft_lsttoarr(t_list *lst);
t_list					*ft_arrtolst(void **arr, int size);
t_list					*ft_lstnew_cc(void *content, size_t content_size);
t_list					*ft_lstnew(void const *content, size_t content_size);
void					ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
void					ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void					ft_lstadd(t_list **alst, t_list *new);
void					ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list					*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void					ft_lstappend(t_list **lst, t_list *new);
size_t					ft_lstlen(const t_list *lst);
void					ft_lstcorder(t_list **lst);
void					ft_lstswap(t_list *lst, unsigned int p1,
							unsigned int p2);
t_list					*ft_lstget(t_list *lst, unsigned int idx);
void					*ft_lstdequeue(t_list **root);
void					ft_lstdelsafe(t_list **lst, void *data, \
							int (*cmp)(void *cdata, void *data),
								void (*del)(void *, size_t));
int						ft_lstgetidx(t_list *lst, void *data, \
							int (*check)(void *elem, void *data));
void					*ft_lstpop(t_list **lst);
void					*ft_lstpeeklast(t_list *lst);
void					ft_qslist(t_list **lst, int (*cmp)(void *, void *));

/*
** Doubly linked list
*/

t_list_de				*ft_lstnew_de(void const *content, size_t content_size);
void					ft_lstdelone_de(t_list_de **alst,\
							void (*del)(void*, size_t));
void					ft_lstdel_de(t_list_de **alst,
							void (*del)(void*, size_t));
void					ft_lstadd_de(t_list_de **alst, t_list_de *new);
void					ft_lstiter_de(t_list_de *lst,
							void (*f)(t_list_de *elem));
t_list_de				*ft_lstmap_de(t_list_de *lst,
							t_list_de *(*f)(t_list_de *elem));
void					ft_lstappend_de(t_list_de **lst, t_list_de *new);
size_t					ft_lstlen_de(const t_list_de *lst);
void					ft_lstcorder_de(t_list_de **lst);
void					ft_lstswap_de(t_list_de *lst, unsigned int p1,
							unsigned int p2);
t_list_de				*ft_lstget_de(t_list_de *lst, unsigned int idx);
void					ft_lst_sdn(t_list_de **dil);
t_pair					*ft_newpair(void *fst, size_t fst_size,
							void *scd, size_t scd_size);
t_pair					*ft_newpair_cc(void *fst, void *scd);
char					*ft_strimplode(char **arr, int size, char *glue);
int						ft_arrgetidx(void **arr, int size, void *data,
							int (*check)(void *elem, void *data));

/*
** Tree
*/

t_tree					*ft_treenew(void *content, size_t content_size);
t_tree					*ft_treenew_cc(void *content, size_t content_size);
t_tree					*ft_treenew_spec(void *content, size_t content_size,
							void *(*dup_content)(void *content));
void					ft_treeadd_kid(t_tree **tree, t_tree *new);
void					ft_treedel(t_tree **tree,
							void (*del)(void *content, size_t content_size));
void					ft_qstreelevel(t_tree **tree,
							int (*cmp)(void *, void *));
void					**ft_treeleveltoarr(t_tree *tree);
size_t					ft_treelevellen(const t_tree *tree);
void					ft_treeleveldel(t_tree **tree,
							void (*del)(void*, size_t));
t_tree					*ft_arrtotreelevel(void **arr, int size);

#endif
