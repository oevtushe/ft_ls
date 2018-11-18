/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 15:32:51 by oevtushe          #+#    #+#             */
/*   Updated: 2017/11/07 19:02:33 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	len_nd;
	size_t	i;

	i = 0;
	len_nd = ft_strlen(needle);
	if (needle[0] == '\0')
		return ((char*)haystack);
	while (haystack[i] != '\0' && i < len)
	{
		if (haystack[i] == needle[0])
			if (i + len_nd <= len \
					&& ft_strncmp(&haystack[i], needle, len_nd) == 0)
				return ((char*)&haystack[i]);
		++i;
	}
	return (NULL);
}
