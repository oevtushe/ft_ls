/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:59:34 by oevtushe          #+#    #+#             */
/*   Updated: 2017/11/20 08:07:00 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char *copy;

	copy = NULL;
	if (s1)
	{
		copy = ft_strnew(ft_strlen(s1));
		if (copy)
			ft_strcpy(copy, s1);
	}
	return (copy);
}
