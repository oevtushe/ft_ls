/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 09:25:37 by oevtushe          #+#    #+#             */
/*   Updated: 2017/11/20 07:37:57 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	substr = NULL;
	if (s)
	{
		i = len;
		substr = ft_strnew(len);
		if (substr)
			while (i--)
				substr[i] = s[start + i];
	}
	return (substr);
}
