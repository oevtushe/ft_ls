/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unsigned_decimal_modifiers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:50:40 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:43:40 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

void	unsigned_decimal_modifiers(t_ftype *ft, va_list ap, t_gdata *gdata)
{
	if (ft->modifier == M_LL)
		gdata->data.ulli = va_arg(ap, unsigned long long int);
	else if (ft->modifier == M_L || ft->type == T_LUNSIGNED)
		gdata->data.uli = va_arg(ap, unsigned long int);
	else if (ft->modifier == M_HH)
		gdata->data.uc = va_arg(ap, unsigned int);
	else if (ft->modifier == M_H)
		gdata->data.usi = va_arg(ap, unsigned int);
	else if (ft->modifier == M_J)
		gdata->data.uim = va_arg(ap, uintmax_t);
	else if (ft->modifier == M_Z)
		gdata->data.szi = va_arg(ap, size_t);
	else
		gdata->data.ui = va_arg(ap, unsigned int);
}
