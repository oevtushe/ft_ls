/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 17:47:03 by oevtushe          #+#    #+#             */
/*   Updated: 2017/11/16 16:19:47 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	size_t	len2;

	i = 0;
	j = ft_strlen(s1);
	len2 = ft_strlen(s2);
	while (i < len2)
	{
		s1[j] = s2[i];
		++j;
		++i;
	}
	s1[j] = '\0';
	return (s1);
}
