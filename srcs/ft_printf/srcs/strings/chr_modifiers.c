/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chr_modifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:39:31 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:39:33 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

void	chr_modifiers(t_ftype *full_type, va_list ap, t_gdata *gdata)
{
	if (full_type->modifier == M_L || full_type->type == T_WCHR)
		gdata->data.wi = va_arg(ap, wint_t);
	else
		gdata->data.c = va_arg(ap, int);
}
