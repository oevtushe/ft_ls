/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:49:39 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/10 15:49:45 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

char	*hex_manager(t_format *sfmt, size_t *len)
{
	uintmax_t	uval;
	char		*res;

	digits_flag_except(sfmt, 1);
	uval = sfmt->gdata->data.uim;
	res = ft_uitoabase_gen(uval, 0, 16);
	if (sfmt->flag_sharp && uval)
	{
		zeroes_handling(&res, 2, sfmt);
		ft_strconnect(&res, "0x", -1);
	}
	else
		zeroes_handling(&res, 0, sfmt);
	if (sfmt->gdata->full_type->type == T_BHEX)
		ft_strtoupper(res);
	spaces_handling(&res, sfmt);
	*len = ft_strlen(res);
	return (res);
}
