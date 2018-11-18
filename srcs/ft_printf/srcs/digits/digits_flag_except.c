/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_flag_except.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:04:42 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/24 15:04:44 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Excludes wrong combinations of flags.
**
** @param	sfmt		format to be normalized.
** @param	magic_val	if 1 then flags plus and space will be turned off
**						(in cases like value in sfmt is negative
**						or unsigned).
*/

void	digits_flag_except(t_format *sfmt, int magic_val)
{
	if (sfmt->flag_minus && sfmt->flag_zero)
		sfmt->flag_zero = 0;
	if (sfmt->precision >= 0 && sfmt->flag_zero)
		sfmt->flag_zero = 0;
	if (sfmt->flag_plus && sfmt->flag_space)
		sfmt->flag_space = 0;
	if (magic_val && sfmt->flag_plus)
		sfmt->flag_plus = 0;
	if (magic_val && sfmt->flag_space)
		sfmt->flag_space = 0;
}
