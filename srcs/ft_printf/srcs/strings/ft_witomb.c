/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_witomb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:39:49 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:45:13 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Converts utf8 code @param wi to multibyte string.
**
** @param	wi	utf8 code to be converted.
**
** @return		multibyte string based on @param wi code.
*/

char	*ft_witomb(wint_t wi)
{
	size_t			len;
	size_t			i;
	size_t			res_idx;
	char			*res;
	unsigned char	*cst;

	len = sizeof(wint_t);
	i = len;
	res_idx = 0;
	cst = (unsigned char *)&wi;
	res = ft_strnew(len);
	if (res)
	{
		while (i--)
			if (cst[i])
				res[res_idx++] = cst[i];
		if (res_idx < len)
			ft_str_realloc(&res, res_idx);
	}
	return (res);
}
