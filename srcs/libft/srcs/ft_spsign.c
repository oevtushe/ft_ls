/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spsign.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 11:55:39 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/10 10:27:38 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Separates sign from value and write unsigned part of him
** in unsigned type. Sign is also will be write in appropriate
** param.
**
** @param	val		value to be separated.
** @param	uval	storage for unsigned part of value.
** @param	sign	storage for sign (1 positive 0 negative).
*/

void	ft_spsign(intmax_t val, uintmax_t *uval, int *sign)
{
	if (uval && sign)
	{
		if (val >= 0)
		{
			*sign = 0;
			*uval = val;
		}
		else
		{
			*sign = 1;
			*uval = val * -1LL;
		}
	}
}
