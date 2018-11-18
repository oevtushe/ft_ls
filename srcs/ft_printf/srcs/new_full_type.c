/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_full_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:36:46 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:36:48 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

t_ftype	*new_full_type(t_type type, t_modifier modifier)
{
	t_ftype	*full_type;

	full_type = (t_ftype *)ft_memalloc(sizeof(t_ftype));
	if (full_type)
	{
		full_type->type = type;
		full_type->modifier = modifier;
	}
	return (full_type);
}
