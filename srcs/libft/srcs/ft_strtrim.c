/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:38:05 by oevtushe          #+#    #+#             */
/*   Updated: 2017/11/20 08:51:16 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	begin;
	size_t	end;
	size_t	len;
	char	*res;

	res = NULL;
	if (s)
	{
		begin = 0;
		len = ft_strlen(s);
		if (len)
		{
			end = len - 1;
			while (begin < end && \
					(s[begin] == ' ' || s[begin] == '\t' || s[begin] == '\n'))
				++begin;
			while (end >= begin && \
					(s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
				--end;
			res = ft_strsub(s, begin, end - begin + 1);
		}
		else
			res = ft_strnew(0);
	}
	return (res);
}
