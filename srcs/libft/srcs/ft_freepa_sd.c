/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freepa_sd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/31 18:30:13 by oevtushe          #+#    #+#             */
/*   Updated: 2018/08/08 18:09:32 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function deletes array of pointers with specified size
**
** Notice: the content has to have basic type (char *, int *) etc.
** Suffix '_sd' means 'simple data'
*/

void	ft_freepa_sd(void ***arr, int size)
{
	int i;

	i = 0;
	if (arr && *arr)
	{
		while (i < size)
			ft_memdel((void **)&(*arr)[i++]);
		ft_memdel((void **)arr);
	}
}
