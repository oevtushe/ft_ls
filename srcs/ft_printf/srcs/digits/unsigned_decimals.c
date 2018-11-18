/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_decimals.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:50:43 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/10 15:48:21 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

char		*unsigned_decimal_manager(t_format *sfmt, size_t *len)
{
	uintmax_t	uval;
	char		*res;

	digits_flag_except(sfmt, 1);
	uval = sfmt->gdata->data.uim;
	res = ft_uitoabase_gen(uval, 0, 10);
	if (sfmt->flag_squote && MB_CUR_MAX > 0)
		group_by_thousands(&res);
	zeroes_handling(&res, 0, sfmt);
	spaces_handling(&res, sfmt);
	*len = ft_strlen(res);
	return (res);
}
