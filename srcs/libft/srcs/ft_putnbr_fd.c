/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:29:22 by oevtushe          #+#    #+#             */
/*   Updated: 2017/10/30 18:41:34 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_putnbr_help(long int n, int fd)
{
	if (n <= 9)
	{
		ft_putchar_fd(n + '0', fd);
		return ;
	}
	ft_putnbr_help(n / 10, fd);
	ft_putchar_fd((n % 10) + '0', fd);
}

void		ft_putnbr_fd(int n, int fd)
{
	long int nn;

	nn = n;
	if (nn < 0)
	{
		ft_putchar_fd('-', fd);
		nn *= -1;
	}
	ft_putnbr_help(nn, fd);
}
