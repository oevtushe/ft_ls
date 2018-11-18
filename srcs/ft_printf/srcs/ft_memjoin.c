/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:42:55 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/10 15:45:06 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_helpers.h"

/*
** Connects two memory blocks together.
**
** @param	p1		pointer at the first memory block.
** @param	sp1		size of data p1 points to.
** @param	p2		pointer to second memory block.
** @param	sp2		size of data p2 points to.
**
** @return			memory block filled by data from @param p1 and @param p2.
*/

void	*ft_memjoin(void *p1, size_t sp1, void *p2, size_t sp2)
{
	unsigned char *res;

	res = (unsigned char *)ft_memalloc(sizeof(unsigned char) * (sp1 + sp2));
	if (res)
	{
		ft_memcpy(res, p1, sp1);
		ft_memcpy(res + sp1, p2, sp2);
	}
	return (res);
}
