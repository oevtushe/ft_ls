/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_decimals.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:50:26 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/10 15:47:40 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

static void			handle_signs(t_format *sfmt, char **res, int sign)
{
	if (sfmt->flag_plus)
		ft_strconnect(res, "+", -1);
	else if (sfmt->flag_space)
		ft_strconnect(res, " ", -1);
	else if (sign > 0)
		ft_strconnect(res, "-", -1);
}

static int			get_dec_prefix(t_format *sfmt, int sign)
{
	int	prefix;

	prefix = 0;
	if ((sign == 0 && (sfmt->flag_plus || sfmt->flag_space)) ||
			sign)
		prefix = 1;
	return (prefix);
}

char				*signed_decimal_manager(t_format *sfmt, size_t *len)
{
	int			sign;
	intmax_t	val;
	uintmax_t	uval;
	char		*res;
	int			prefix;

	sign = 0;
	val = signed_gdata_load(sfmt->gdata);
	ft_spsign(val, &uval, &sign);
	prefix = get_dec_prefix(sfmt, sign);
	digits_flag_except(sfmt, sign);
	res = ft_uitoabase_gen(uval, 0, 10);
	if (sfmt->flag_squote && MB_CUR_MAX > 1)
		group_by_thousands(&res);
	zeroes_handling(&res, prefix, sfmt);
	handle_signs(sfmt, &res, sign);
	spaces_handling(&res, sfmt);
	*len = ft_strlen(res);
	return (res);
}
