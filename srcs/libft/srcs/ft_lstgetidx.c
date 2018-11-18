/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstgetidx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 19:21:50 by oevtushe          #+#    #+#             */
/*   Updated: 2018/08/08 18:19:20 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function searchs element in the list.
**
** check function has to return 1 if elements is equall, 0 otherwise
**
** @return	element index if first one is present in the list,
**			-1 otherwise
*/

int	ft_lstgetidx(t_list *lst, void *data, int (*check)(void *elem, void *data))
{
	int i;

	i = 0;
	if (check)
	{
		while (lst)
		{
			if (check(lst->content, data))
				return (i);
			lst = lst->next;
			++i;
		}
	}
	return (-1);
}
