/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptr_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:47 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/10 15:40:44 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

char	*ptr_manager(t_format *sfmt, size_t *len)
{
	char	*res;
	char	*tmp;
	size_t	val;

	val = (size_t)sfmt->gdata->data.pv;
	res = ft_uitoabase_gen(val, 0, 16);
	if (res)
	{
		zeroes_handling(&res, 0, sfmt);
		tmp = res;
		res = ft_strjoin("0x", res);
		spaces_handling(&res, sfmt);
		ft_strdel(&tmp);
	}
	*len = ft_strlen(res);
	return (res);
}
