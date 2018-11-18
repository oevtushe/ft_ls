/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intln.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 13:55:08 by oevtushe          #+#    #+#             */
/*   Updated: 2018/04/25 13:55:33 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intln_help(long int n)
{
	if (n <= 9)
		return (1);
	return (1 + ft_intln_help(n / 10));
}

int			ft_intln(int n)
{
	long int	nn;
	int			extra;

	nn = n;
	extra = 0;
	if (nn < 0)
	{
		extra = 1;
		nn *= -1;
	}
	return (extra + ft_intln_help(nn));
}
