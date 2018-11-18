/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 08:32:11 by oevtushe          #+#    #+#             */
/*   Updated: 2017/11/16 17:51:11 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*fresh;

	fresh = NULL;
	if (s && f)
	{
		i = 0;
		fresh = ft_strnew(ft_strlen(s));
		if (fresh)
		{
			while (s[i] != '\0')
			{
				fresh[i] = f(i, s[i]);
				++i;
			}
		}
	}
	return (fresh);
}
