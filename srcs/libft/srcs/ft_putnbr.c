/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:02:43 by oevtushe          #+#    #+#             */
/*   Updated: 2017/10/30 18:26:20 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_help(long int n)
{
	if (n <= 9)
	{
		ft_putchar(n + '0');
		return ;
	}
	ft_putnbr_help(n / 10);
	ft_putchar((n % 10) + '0');
}

void		ft_putnbr(int n)
{
	long int nn;

	nn = n;
	if (nn < 0)
	{
		ft_putchar('-');
		nn *= -1;
	}
	ft_putnbr_help(nn);
}
