/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isvldint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/19 15:59:08 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/12 17:07:13 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	vldval(unsigned int res, int sign, char *val)
{
	if ((sign > 0 && res > INT_MAX) ||
			(sign < 0 && res > (-1L * INT_MIN)) ||
				(*val))
		return (0);
	return (1);
}

/*
** Check if a string is a valid integer.
** '+', '-' are allowed.
*/

int			ft_isvldint(char *str)
{
	int				i;
	unsigned int	res;
	int				sign;
	int				len;

	i = 0;
	sign = 1;
	res = 0;
	len = -1;
	if (str[i] == '-')
	{
		sign = -1;
		++i;
	}
	else if (str[i] == '+')
		++i;
	if (str[i] == '\0')
		return (0);
	while (str[i] == '0')
		++i;
	while (++len < 10 && ft_isdigit(str[i]))
		res = res * 10 + str[i++] - '0';
	return (vldval(res, sign, &str[i]));
}
