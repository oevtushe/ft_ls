/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:37:59 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:38:08 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Function handle cases when precision was
** initialized from data array and has negative value.
**
** @param	sfmt	format to be normalized.
*/

void	normalize_width(t_format *sfmt)
{
	unsigned int	width;

	if (sfmt->width < 0)
	{
		width = sfmt->width * -1;
		sfmt->flag_minus = 1;
	}
	else
		width = sfmt->width;
	sfmt->width = width;
}
