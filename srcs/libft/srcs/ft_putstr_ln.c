/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_ln.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:43:01 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/10 10:19:16 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

/*
** String printer. Prints exactly @param len characters.
**
** @param	str		string to be printed.
** @param	cnt		count of character to be printed.
*/

void	ft_putstr_ln(const char *str, size_t ln)
{
	size_t i;

	i = 0;
	if (str)
	{
		while (i < ln)
			write(1, &str[i++], 1);
	}
}
