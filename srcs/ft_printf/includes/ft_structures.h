/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structures.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:49:19 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 17:23:25 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_STRUCTURES_H
# define _FT_STRUCTURES_H

# include <string.h>
# include <inttypes.h>
# include <wchar.h>

# define DISPATCHER_SIZE 11

typedef enum					e_type
{
	T_DEC = 'd',
	T_DEC2 = 'i',
	T_LDEC = 'D',
	T_STR = 's',
	T_CHR = 'c',
	T_WCHR = 'C',
	T_UNSIGNED = 'u',
	T_LUNSIGNED = 'U',
	T_PT = '%',
	T_WSTR = 'S',
	T_PTR = 'p',
	T_OCT = 'o',
	T_LOCT = 'O',
	T_HEX = 'x',
	T_BINARY = 'b',
	T_SPREAD = '&',
	T_BHEX = 'X'
}								t_type;

typedef enum					e_modifier
{
	M_DEFAULT,
	M_L,
	M_LL,
	M_H,
	M_HH,
	M_J,
	M_Z
}								t_modifier;

typedef union					u_data
{
	short int				si;
	unsigned short int		usi;

	int						i;
	long int				li;
	long long int			lli;
	ssize_t					sszi;
	size_t					szi;
	intmax_t				im;

	unsigned int			ui;
	unsigned long int		uli;
	unsigned long long int	ulli;
	uintmax_t				uim;

	char					c;
	unsigned char			uc;
	wchar_t					wc;
	wint_t					wi;
	char					*pc;
	wchar_t					*pwc;

	void					*pv;

}								t_data;

typedef struct					s_full_type
{
	t_type		type;
	t_modifier	modifier;
}								t_ftype;

typedef struct					s_gdata
{
	t_data					data;
	t_ftype					*full_type;
}								t_gdata;

typedef struct					s_format
{
	int						width;
	int						precision;

	int						flag_plus;
	int						flag_minus;
	int						flag_space;
	int						flag_zero;
	int						flag_sharp;
	int						flag_squote;

	t_gdata					*gdata;
}								t_format;
typedef struct					s_mng_dpc
{
	t_type	type;
	char	*(*manager)(t_format *sfmt, size_t *len);
}								t_mng_dpc;

#endif
