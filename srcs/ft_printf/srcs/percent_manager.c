/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent_manager.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:35 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:48:36 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

char	*percent_manager(t_format *sfmt, size_t *len)
{
	char *res;

	res = ft_strdup("%");
	sfmt->precision = -1;
	digits_flag_except(sfmt, 1);
	zeroes_handling(&res, 0, sfmt);
	spaces_handling(&res, sfmt);
	free_gdata(&sfmt->gdata);
	*len = ft_strlen(res);
	return (res);
}
