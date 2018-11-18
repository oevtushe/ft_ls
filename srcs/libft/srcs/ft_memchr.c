/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 12:32:03 by oevtushe          #+#    #+#             */
/*   Updated: 2017/11/16 16:29:16 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*arr;
	unsigned char	symb;

	i = 0;
	arr = (unsigned char*)s;
	symb = c;
	while (i < n)
	{
		if (arr[i] == symb)
			return (&arr[i]);
		++i;
	}
	return (NULL);
}
