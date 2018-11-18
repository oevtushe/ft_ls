/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:56:19 by oevtushe          #+#    #+#             */
/*   Updated: 2017/11/12 16:50:09 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memdup(void *data, size_t size)
{
	void *copy;

	copy = NULL;
	if (data)
	{
		copy = ft_memalloc(size);
		if (copy)
			ft_memcpy(copy, data, size);
	}
	return (copy);
}
