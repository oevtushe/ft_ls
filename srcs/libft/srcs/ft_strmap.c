/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 08:11:07 by oevtushe          #+#    #+#             */
/*   Updated: 2017/11/16 17:48:11 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
				fresh[i] = f(s[i]);
				++i;
			}
		}
	}
	return (fresh);
}
