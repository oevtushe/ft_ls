/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_arr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:14 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 17:07:25 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Function read data from @param ap accordingly to @param cur_type.
**
** @param	ap			va_list to read data from.
** @param	cur_type	type to read from @param ap.
**
** @return				gdata readed from @param ap.
*/

static t_gdata		*get_data(t_ftype *cur_type, va_list ap)
{
	t_gdata	*gdata;

	gdata = (t_gdata *)ft_memalloc(sizeof(t_gdata));
	gdata->full_type = cur_type;
	if (cur_type->type == T_DEC || cur_type->type == T_BINARY)
		signed_decimal_modifiers(cur_type, ap, gdata);
	else if (cur_type->type == T_UNSIGNED || cur_type->type == T_OCT ||
			cur_type->type == T_HEX ||
			cur_type->type == T_BHEX ||
			cur_type->type == T_LOCT)
		unsigned_decimal_modifiers(cur_type, ap, gdata);
	else if (cur_type->type == T_STR)
		str_modifiers(cur_type, ap, gdata);
	else if (cur_type->type == T_CHR || cur_type->type == T_SPREAD)
		chr_modifiers(cur_type, ap, gdata);
	else if (cur_type->type == T_PTR)
		gdata->data.pv = va_arg(ap, void *);
	return (gdata);
}

/*
** Function create data arr based on types in format
** strings in @param extra.
** Type array data is cached by data array, so we don't
** need to free them here.
**
** @param	extra	list with format strings.
** @param	ap		va_list from which data is readed.
**
** @return			array of data.
*/

t_gdata				**get_data_arr(t_list *extra, va_list ap, int lt)
{
	t_gdata		**gdata;
	t_ftype		**type_arr;
	int			idx;

	idx = get_arr_size(extra, lt);
	gdata = (t_gdata **)ft_memalloc(sizeof(t_gdata *) * (idx + 1));
	type_arr = get_type_arr(extra, idx, lt);
	idx = -1;
	while (type_arr[++idx])
		gdata[idx] = get_data(type_arr[idx], ap);
	free(type_arr);
	return (gdata);
}
