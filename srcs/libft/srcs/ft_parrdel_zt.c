/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parrdel_zt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:30:20 by oevtushe          #+#    #+#             */
/*   Updated: 2018/07/23 19:30:31 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Functon deletes null terminated arr of pointers
*/

void	ft_parrdel_zt(void ***arr)
{
	size_t i;

	i = 0;
	if (arr && *arr)
	{
		while ((*arr)[i])
			ft_memdel((void**)&(*arr)[i++]);
		ft_memdel((void**)arr);
		*arr = NULL;
	}
}
