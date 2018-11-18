/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 11:58:31 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/06 17:23:48 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*se;

	len = ft_strlen(s);
	se = (char*)&s[len];
	while (se >= s)
	{
		if (*se == c)
			return ((char*)se);
		se--;
	}
	return (NULL);
}
