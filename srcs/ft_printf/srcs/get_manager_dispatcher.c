/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_manager_dispatcher.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 15:48:58 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 17:07:39 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

t_mng_dpc	*new_dpc(t_type type, char *(*manager)(t_format *sfmt, size_t *len))
{
	t_mng_dpc	*dpc;

	dpc = (t_mng_dpc *)ft_memalloc(sizeof(t_mng_dpc));
	if (dpc)
	{
		dpc->type = type;
		dpc->manager = manager;
	}
	return (dpc);
}

/*
** Creates manager dispatcher.
**
** @return		manager dispatcher.
*/

t_mng_dpc	**get_manager_dispatcher(void)
{
	t_mng_dpc **dispatcher;

	dispatcher = (t_mng_dpc **)ft_memalloc(sizeof(t_mng_dpc *) *
			(DISPATCHER_SIZE + 1));
	dispatcher[0] = new_dpc(T_DEC, signed_decimal_manager);
	dispatcher[1] = new_dpc(T_UNSIGNED, unsigned_decimal_manager);
	dispatcher[2] = new_dpc(T_PT, percent_manager);
	dispatcher[3] = new_dpc(T_STR, str_manager);
	dispatcher[4] = new_dpc(T_CHR, chr_manager);
	dispatcher[5] = new_dpc(T_PTR, ptr_manager);
	dispatcher[6] = new_dpc(T_OCT, octal_manager);
	dispatcher[7] = new_dpc(T_HEX, hex_manager);
	dispatcher[8] = new_dpc(T_BHEX, hex_manager);
	dispatcher[9] = new_dpc(T_BINARY, binary_manager);
	dispatcher[10] = new_dpc(T_SPREAD, repeat_manager);
	dispatcher[11] = NULL;
	return (dispatcher);
}
