/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:44:51 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/25 13:57:47 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		ft_itoa_help(long int n, char *str, int *idx)
{
	if (n <= 9)
	{
		str[(*idx)++] = n + '0';
		return ;
	}
	ft_itoa_help(n / 10, str, idx);
	str[(*idx)++] = (n % 10) + '0';
}

char			*ft_itoa(int n)
{
	char		*res;
	long int	nn;
	int			idx;

	idx = 0;
	nn = n;
	res = ft_strnew(ft_intln(n));
	if (res)
	{
		if (nn < 0)
		{
			res[idx++] = '-';
			nn *= -1;
		}
		ft_itoa_help(nn, res, &idx);
	}
	return (res);
}
