/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   repeat_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 16:44:59 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 17:27:19 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Manager adds passed char N times (parameter width)
*/

char	*repeat_manager(t_format *sfmt, size_t *len)
{
	char	*res;
	size_t	ln;

	ln = sfmt->width ? sfmt->width : 1;
	res = ft_strnew(ln);
	ft_memset(res, sfmt->gdata->data.c, ln);
	*len = ln;
	return (res);
}
