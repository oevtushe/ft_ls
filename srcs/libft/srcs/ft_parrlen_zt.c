/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parrlen_zt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:29:00 by oevtushe          #+#    #+#             */
/*   Updated: 2018/07/23 19:44:51 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function calculates the length of null terminated array of pointers
*/

size_t	ft_parrlen_zt(void **arr)
{
	size_t	len;

	len = 0;
	if (arr)
	{
		while (arr[len])
			++len;
	}
	return (len);
}
