/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_group_by.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 13:01:59 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/26 13:02:01 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Group string into blocks delimited by spaces.
**
** @param	val		string to be grouped.
** @param	cnt		size of group.
*/

void	ft_group_by(char **val, int cnt)
{
	size_t	old_len;
	size_t	new_len;
	size_t	idx;
	char	*res;

	if (val && *val && cnt)
	{
		old_len = ft_strlen(*val);
		new_len = old_len + old_len / (cnt + 1);
		res = ft_strnew(new_len);
		idx = 0;
		while (old_len--)
		{
			if (idx++ && idx % (cnt + 1) == 0)
				res[--new_len] = ' ';
			res[--new_len] = (*val)[old_len];
		}
		ft_strdel(val);
		*val = res;
	}
}
