/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcorder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 08:38:39 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 12:17:26 by oevtushe         ###   ########.fr       */
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

void	ft_lstcorder(t_list **lst)
{
	t_list *prev;
	t_list *cur;
	t_list *next;

	prev = NULL;
	cur = NULL;
	if (lst)
	{
		next = *lst;
		while (next)
		{
			cur = next;
			next = cur->next;
			cur->next = prev;
			prev = cur;
		}
		*lst = cur;
	}
}
