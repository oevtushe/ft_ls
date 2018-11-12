/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrtotreelevel.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:09:01 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/10 17:15:34 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Function converts array of pointers to list
** Data from the array won't be copied, just captured by pointer
*/

t_tree	*ft_arrtotreelevel(void **arr, int size)
{
	int		i;
	t_tree	*begin;
	t_tree	*last;

	i = 0;
	begin = NULL;
	last = NULL;
	if (size && arr)
	{
		last = ft_treenew_cc(arr[i++], sizeof(t_tree));
		begin = last;
		while (i < size)
		{
			last->siblings = ft_treenew_cc(arr[i], sizeof(t_tree));
			last = last->siblings;
			++i;
		}
	}
	return (begin);
}
