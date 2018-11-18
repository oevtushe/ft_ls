/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_full_type.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:37:31 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:37:39 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

static int	is_tonormalize(t_type type)
{
	if (type == T_LDEC || type == T_LUNSIGNED || type == T_WCHR ||
		type == T_WSTR || type == T_WSTR || type == T_LOCT)
		return (1);
	return (0);
}

/*
** After this function no differences between type 'D' and type "ld"
**
** @param full_type	type to normalize.
*/

void		normalize_full_type(t_ftype *full_type)
{
	if (full_type->type == T_DEC2)
	{
		full_type->type = T_DEC;
		return ;
	}
	if (is_tonormalize(full_type->type))
	{
		if (full_type->type == T_LDEC)
			full_type->type = T_DEC;
		else if (full_type->type == T_LUNSIGNED)
			full_type->type = T_UNSIGNED;
		else if (full_type->type == T_WCHR)
			full_type->type = T_CHR;
		else if (full_type->type == T_WSTR)
			full_type->type = T_STR;
		else if (full_type->type == T_LOCT)
			full_type->type = T_OCT;
		full_type->modifier = M_L;
	}
}
