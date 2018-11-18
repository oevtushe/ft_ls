/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_type_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:42:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/26 13:42:37 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Function reads type from @param str.
**
** Min len of format string is 2, no bug here.
** full_type->type = str[len - 1] - is valid because we already
** checked type validness.
** Here type 'D' and type 'ld' has differences
**
** @param	str		string to read type from.
** @param	len		len of @param str.
*/

static t_ftype	*get_type(const char *str, size_t len)
{
	t_ftype *full_type;

	full_type = (t_ftype *)ft_memalloc(sizeof(t_ftype));
	if (str[len - 2] == 'l' && str[len - 3] == 'l')
		full_type->modifier = M_LL;
	else if (str[len - 2] == 'h' && str[len - 3] == 'h')
		full_type->modifier = M_HH;
	else if (str[len - 2] == 'l')
		full_type->modifier = M_L;
	else if (str[len - 2] == 'h')
		full_type->modifier = M_H;
	else if (str[len - 2] == 'z')
		full_type->modifier = M_Z;
	else if (str[len - 2] == 'j')
		full_type->modifier = M_J;
	else
		full_type->modifier = M_DEFAULT;
	full_type->type = str[len - 1];
	normalize_full_type(full_type);
	return (full_type);
}

/*
** Function defines and writes type in specified index into @param ta.
** If two format string has refferences to one index in arr - first has
** preference.
**
** @param	str		format string type is readed from.
** @param	len		length of @params str.
** @param	ta		pointer to type array.
** @param	ti		index to @param ta array.
*/

static void		read_strtd_smp(char *str, size_t len, t_ftype **ta, int *ti)
{
	int		i;
	char	*pos;

	i = 0;
	if (str[len - 1] != '%')
	{
		while ((pos = ft_strchr(&str[i], '*')))
		{
			i = pos - str + 1;
			ta[(*ti)++] = new_full_type(T_DEC, M_DEFAULT);
		}
		ta[(*ti)++] = get_type(str, len);
	}
}

static void		read_strtd_dl(char *str, size_t len, t_ftype **ta, int *ti)
{
	int		i;
	char	*pos;

	i = 0;
	while ((pos = ft_strchr(&str[i], '$')))
	{
		i = pos-- - str + 1;
		while (ft_isdigit(*pos))
			--pos;
		*ti = ft_atoi(pos + 1) - 1;
		if (*pos == '%' && !ta[*ti])
			ta[*ti] = get_type(str, len);
		else if (*pos == '*' && !ta[*ti])
			ta[*ti] = new_full_type(T_DEC, M_DEFAULT);
	}
}

/*
** Function create t_ftype arr based on @param extra list.
**
** @param	extra	list base on arr is creating.
** @param	arr_sz	size of arr.
**
** @return			array of types.
*/

t_ftype			**get_type_arr(t_list *extra, int arr_sz, int lt)
{
	int			ti;
	size_t		len;
	char		*str;
	t_ftype		**type_arr;
	void		(*read_strtd)(char*, size_t, t_ftype**, int*);

	ti = 0;
	type_arr = (t_ftype **)ft_memalloc(sizeof(t_ftype *) * (arr_sz + 1));
	if (lt)
		read_strtd = read_strtd_dl;
	else
		read_strtd = read_strtd_smp;
	while (extra)
	{
		str = (char *)extra->content;
		len = ft_strlen(str);
		if (str[len - 1] != '%')
			read_strtd(str, len, type_arr, &ti);
		extra = extra->next;
	}
	return (type_arr);
}
