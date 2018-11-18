/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:36:00 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:36:07 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Function checks type of logic for specifying index in data array.
** There are 2 types of logic 1 -> dollar, when all formats should
** specify indexes in data array to load from (indexes don't have
** to be in any order), and simple (all data which is not explicitly
** specified in format string will be loaded from data array in some order).
**
** Example of dollar logic: '%2$.3d %.1$d', '%.*1$d'.
** There can't be '%2$d' or '%2$.*d', if one index is specified in dollar
** logic others should be specified in that logic to.
**
** Example of simple logic: '%*d', '%d', '%.*d' etc.
**
** @param	extra	list of format strings.
**
** @return			1 if is dollar logic, 0 otherwise.
*/

int	logic_type(t_list *extra)
{
	int		type;
	char	*str;

	type = 0;
	while (extra)
	{
		str = extra->content;
		if (str[ft_strlen(str) - 1] != '%')
		{
			if (ft_strchr(str, '$'))
				type = 1;
			break ;
		}
		extra = extra->next;
	}
	return (type);
}
