/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcorder_de.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:46:29 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/15 18:04:08 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Changes links order in list so that the last element
** becomes the first one.
** Example:
** 		List entry: 3->2->1->NULL
**		Order changed.
**		List entry: 1->2->3->NULL
**
** @param	lst		list to change order in.
*/

void	ft_lstcorder_de(t_list_de **lst)
{
	t_list_de	*cur;
	t_list_de	*next;

	cur = NULL;
	next = NULL;
	if (lst)
	{
		next = *lst;
		while (next)
		{
			cur = next;
			next = cur->next;
			cur->next = cur->prev;
			cur->prev = next;
		}
		*lst = cur;
	}
}
