/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spaces_handling.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 13:44:06 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/24 13:44:09 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Adds spaces at the beginning of string or at the end. Count of spaces
** depends from width specified in @param sfmt.
**
** @param	sv		string spaces will be added to.
** @param	sfmt	current format.
*/

void	spaces_handling(char **sv, t_format *sfmt)
{
	int		len;
	char	*res;

	res = ft_strdup(*sv);
	if (res)
	{
		len = ft_strlen(res);
		if (sfmt->width > len && sfmt->flag_minus)
			ft_strcntllr(&res, sfmt->width, ' ', 1);
		else if (sfmt->width > len)
			ft_strcntllr(&res, sfmt->width, ' ', -1);
		ft_strdel(sv);
		*sv = res;
	}
}
