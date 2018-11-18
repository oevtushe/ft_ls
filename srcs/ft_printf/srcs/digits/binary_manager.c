/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 10:43:03 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/10 15:49:21 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

char	*binary_manager(t_format *sfmt, size_t *len)
{
	intmax_t	val;
	uintmax_t	uval;
	int			sign;
	char		*res;

	val = signed_gdata_load(sfmt->gdata);
	ft_spsign(val, &uval, &sign);
	digits_flag_except(sfmt, sign > 0);
	res = ft_uitoabase_gen(uval, 0, 2);
	zeroes_handling(&res, 0, sfmt);
	if (sfmt->flag_squote)
		ft_group_by(&res, 8);
	spaces_handling(&res, sfmt);
	*len = ft_strlen(res);
	return (res);
}
