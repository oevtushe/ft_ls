/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_type.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:07:26 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 17:18:26 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

int		is_type(char c)
{
	int valid;

	valid = 0;
	if (c == T_OCT || c == T_LOCT || c == T_CHR || c == T_WCHR ||
		c == T_DEC || c == T_DEC2 || c == T_LDEC || c == T_HEX ||
		c == T_BHEX || c == T_PT || c == T_PTR || c == T_STR ||
		c == T_WSTR || c == T_UNSIGNED || c == T_LUNSIGNED ||
		c == T_BINARY || c == T_SPREAD)
		valid = 1;
	return (valid);
}
