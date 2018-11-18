/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 19:58:40 by oevtushe          #+#    #+#             */
/*   Updated: 2017/11/16 17:20:12 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*mem;

	if (!size)
		return (NULL);
	i = 0;
	mem = (char*)malloc(size);
	if (!mem)
		return (NULL);
	while (i < size)
		mem[i++] = 0;
	return (mem);
}
