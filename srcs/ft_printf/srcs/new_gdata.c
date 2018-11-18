/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_gdata.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:30 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:37:13 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

t_gdata	*new_gdata(void)
{
	t_gdata *gdata;

	gdata = (t_gdata *)ft_memalloc(sizeof(t_gdata));
	if (gdata)
	{
		gdata->full_type = (t_ftype *)ft_memalloc(sizeof(t_ftype));
		if (!gdata->full_type)
			ft_memdel((void **)&gdata);
	}
	return (gdata);
}
