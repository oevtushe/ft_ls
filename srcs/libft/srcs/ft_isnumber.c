/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:10:34 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/23 09:31:23 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Functions checks if whole string is number. No spaces/tabs/alpha's and
** other symbols allowed. Only [+-0-9]+
** Empty string isn't considered as number.
**
** @param	str		string to check.
** @return	1		if given sting is number.
**			0		if not.
*/

int		ft_isnumber(char *str)
{
	int		rv;
	size_t	i;

	i = 0;
	rv = 0;
	if (str)
	{
		if (str[i] == '-' || str[i] == '+')
			++i;
		while (ft_isdigit(str[i]))
			++i;
		if (i && !str[i])
			rv = 1;
	}
	return (rv);
}
