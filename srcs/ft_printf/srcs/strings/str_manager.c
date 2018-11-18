/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_manager.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:40:13 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:46:21 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

static char			*wcs_to_utf8(wchar_t *wcs, int len)
{
	char			*res;
	char			*dp;
	wint_t			utf;
	int				sum_len;
	int				cnt;

	res = ft_strnew(0);
	sum_len = 0;
	cnt = -1;
	while ((sum_len < len || len < 0) && wcs[++cnt])
	{
		utf = ft_utu8(wcs[cnt]);
		dp = ft_witomb(utf);
		sum_len += ft_strlen(dp);
		if (sum_len > len && len >= 0)
		{
			ft_strdel(&dp);
			break ;
		}
		ft_strconnect(&res, dp, 1);
		ft_strdel(&dp);
	}
	return (res);
}

static char			*str_null(t_format *sfmt, size_t *ln)
{
	char *res;

	sfmt->gdata->data.pc = ft_strdup("(null)");
	res = str_manager(sfmt, ln);
	ft_strdel(&sfmt->gdata->data.pc);
	*ln = ft_strlen(res);
	return (res);
}

char				*str_manager(t_format *sfmt, size_t *ln)
{
	char *res;

	if (sfmt->gdata->data.pc == NULL)
		res = str_null(sfmt, ln);
	else
	{
		if (sfmt->gdata->full_type->modifier == M_L)
			res = wcs_to_utf8(sfmt->gdata->data.pwc, sfmt->precision);
		else
		{
			if (sfmt->precision >= 0)
			{
				res = ft_strnew(sfmt->precision);
				ft_memcpy(res, sfmt->gdata->data.pc, sfmt->precision);
			}
			else
				res = ft_strdup(sfmt->gdata->data.pc);
		}
		spaces_handling(&res, sfmt);
		*ln = ft_strlen(res);
	}
	return (res);
}
