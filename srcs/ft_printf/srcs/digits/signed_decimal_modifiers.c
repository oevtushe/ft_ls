/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_decimal_modifiers.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:49:49 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:49:50 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

void	signed_decimal_modifiers(t_ftype *full_type, va_list ap, t_gdata *gdata)
{
	if (full_type->modifier == M_LL)
		gdata->data.lli = va_arg(ap, long long int);
	else if (full_type->modifier == M_L || full_type->type == T_LDEC)
		gdata->data.li = va_arg(ap, long int);
	else if (full_type->modifier == M_HH)
		gdata->data.c = va_arg(ap, int);
	else if (full_type->modifier == M_H)
		gdata->data.si = va_arg(ap, int);
	else if (full_type->modifier == M_J)
		gdata->data.im = va_arg(ap, intmax_t);
	else if (full_type->modifier == M_Z)
		gdata->data.sszi = va_arg(ap, ssize_t);
	else
		gdata->data.i = va_arg(ap, int);
}
