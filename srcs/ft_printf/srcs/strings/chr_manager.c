/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:38:58 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:44:43 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

static size_t	helper(char **res, t_format *sfmt)
{
	size_t len;

	if ((*res)[0] == '\0')
	{
		spaces_handling(res, sfmt);
		len = ft_strlen(*res) + 1;
		if (sfmt->flag_minus)
		{
			(*res)[0] = 0;
			len--;
		}
		else if (len > 1)
			(*res)[--len - 1] = 0;
	}
	else
	{
		spaces_handling(res, sfmt);
		len = ft_strlen(*res);
	}
	return (len);
}

char			*chr_manager(t_format *sfmt, size_t *len)
{
	char	*res;

	if (sfmt->gdata->full_type->modifier == M_L && MB_CUR_MAX > 1)
		res = ft_witomb(ft_utu8(sfmt->gdata->data.wi));
	else
	{
		res = ft_strnew(1);
		res[0] = sfmt->gdata->data.c;
	}
	*len = helper(&res, sfmt);
	return (res);
}
