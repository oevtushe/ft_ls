/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signed_gdata_load.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:45:09 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/26 16:45:11 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Loads signed number from gdata type.
**
** @param	gdata	signed number container.
**
** @return			signed number.
*/

intmax_t		signed_gdata_load(t_gdata *gdata)
{
	intmax_t vl;

	vl = 0;
	if (gdata->full_type->modifier == M_L)
		vl = gdata->data.li;
	else if (gdata->full_type->modifier == M_LL)
		vl = gdata->data.lli;
	else if (gdata->full_type->modifier == M_H)
		vl = gdata->data.si;
	else if (gdata->full_type->modifier == M_HH)
		vl = gdata->data.c;
	else if (gdata->full_type->modifier == M_J)
		vl = gdata->data.im;
	else if (gdata->full_type->modifier == M_Z)
		vl = gdata->data.sszi;
	else
		vl = gdata->data.i;
	return (vl);
}
