/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outside_param.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:38:26 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:38:35 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Get data (width/precision) from @param gdata by index in @param str
**
** @param	str		string to read index from.
** @param	idx		current position in string.
** @param	gdata	gdata array.
** @param	di		order index in gdata array (in case of simple logic).
**
** @return			width/precision readed from the gdata array.
*/

int	outside_param(const char *str, size_t *idx, t_gdata **gdata, int *di)
{
	int	val;

	val = -1;
	if (ft_isdigit(str[*idx]))
	{
		*di = ft_atoi(&str[*idx]) - 1;
		while (ft_isdigit(str[*idx]))
			++(*idx);
		if (str[*idx] == '$')
		{
			++(*idx);
			val = gdata[*di]->data.i;
		}
	}
	else
		val = gdata[(*di)++]->data.i;
	return (val);
}
