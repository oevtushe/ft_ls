/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcntllr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 16:27:28 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/10 10:33:40 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Recreates string @param str with @param new_len length.
** Oldlength - newlength characters from side specified in @param side
** (where -1 means left, 1 right) will be filled with @param filler character.
**
** @param	str		string to be recreated.
** @param	new_len	length of result string.
** @param	filler	fill character for rest of the string.
** @param	side	side filled string will be added to.
*/

void	ft_strcntllr(char **str, size_t new_len, char filler, int side)
{
	size_t	tjlen;
	size_t	old_len;
	char	*res;
	char	*to_join;

	old_len = ft_strlen(*str);
	if (new_len > old_len)
	{
		tjlen = new_len - old_len;
		to_join = ft_strnew(tjlen);
		if (to_join)
		{
			ft_memset(to_join, filler, tjlen);
			if (side == 1)
				res = ft_strjoin(*str, to_join);
			else
				res = ft_strjoin(to_join, *str);
			if (res)
			{
				ft_strdel(str);
				ft_strdel(&to_join);
				*str = res;
			}
		}
	}
}
