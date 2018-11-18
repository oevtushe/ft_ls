/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_cur_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:21:57 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:22:42 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Function returns data from @param gdata arr by index readed from @param str
** in case of '$' appearence or by index @param di.
** If is '%' type returns new gdata object appropriately initiated.
**
** @param	str		format string.
** @param	idx		current index in format string to check from.
** @param	di		current index in gdata array.
** @param	gd		gdata array.
**
** @return			gdata loaded from array.
*/

t_gdata		*get_cur_data(const char *str, size_t *idx, int *di, t_gdata **gd)
{
	int		j;
	int		ndi;
	t_gdata *gdata;

	j = *idx;
	if (ft_isdigit(str[j]))
	{
		ndi = ft_atoi(&str[j]) - 1;
		while (ft_isdigit(str[j]))
			++j;
		if (str[j] == '$')
		{
			*di = ndi;
			*idx = ++j;
		}
	}
	if (str[ft_strlen(str) - 1] == T_PT)
	{
		gdata = new_gdata();
		gdata->full_type->type = T_PT;
		return (gdata);
	}
	return (gd[(*di)++]);
}
