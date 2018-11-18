/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zeroes_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 13:45:46 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/24 13:45:49 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Handling precision and width with zero flag.
**
** @param	val		string to be modified.
** @param	prefix	prefix which will be added later
**					so we left empty space for him.
** @param	sfmt	format specificator.
*/

void	zeroes_handling(char **val, int prefix, t_format *sfmt)
{
	int len;

	len = ft_strlen(*val);
	if (sfmt->precision > len)
		ft_strcntllr(val, sfmt->precision, '0', -1);
	else if (sfmt->precision == 0 && *val[0] == '0')
	{
		ft_strdel(val);
		*val = ft_strnew(0);
	}
	else if (sfmt->width > len && sfmt->flag_zero)
		ft_strcntllr(val, sfmt->width - prefix, '0', -1);
}
