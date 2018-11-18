/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   octal_manager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:49:45 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/10 15:48:57 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

char		*octal_manager(t_format *sfmt, size_t *len)
{
	uintmax_t	uval;
	char		*res;

	digits_flag_except(sfmt, 1);
	uval = sfmt->gdata->data.uim;
	res = ft_uitoabase_gen(uval, 0, 8);
	zeroes_handling(&res, 0, sfmt);
	if (sfmt->flag_sharp && res[0] != '0')
		ft_strconnect(&res, "0", -1);
	spaces_handling(&res, sfmt);
	*len = ft_strlen(res);
	return (res);
}
