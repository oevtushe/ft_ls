/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   group_by_thousands.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:49:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:49:36 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Splits value given in @param val into groups of thousands.
**
** @param	val		integer value given in the string.
*/

void	group_by_thousands(char **val)
{
	size_t	old_len;
	char	*nstr;
	size_t	ostr_idx;
	size_t	nstr_idx;

	old_len = ft_strlen(*val);
	nstr = ft_strnew(old_len + ((old_len - 1) / 3) * 2);
	nstr_idx = old_len + ((old_len - 1) / 3) * 2;
	ostr_idx = old_len;
	while (ostr_idx--)
	{
		nstr[--nstr_idx] = (*val)[ostr_idx];
		if (nstr_idx && (old_len - ostr_idx) % 3 == 0)
		{
			nstr[--nstr_idx] = 0xA0;
			nstr[--nstr_idx] = 0xC2;
		}
	}
	ft_strdel(val);
	*val = nstr;
}
