/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelsafe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/19 11:53:33 by oevtushe          #+#    #+#             */
/*   Updated: 2018/08/08 18:19:39 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function deletes element from the list and saves the list's linkage
** cmp function should return 1 if cdata is equal to data, 0 otherwise
** del fucntion should delete elem's content
*/

void	ft_lstdelsafe(t_list **lst, void *data,
			int (*cmp)(void *cdata, void *data), void (*del)(void *, size_t))
{
	t_list	*prev;
	t_list	*cur;
	t_list	*next;

	prev = NULL;
	cur = *lst;
	next = cur->next;
	if (!next)
	{
		if (cmp(cur->content, data))
			ft_lstdelone(lst, del);
		return ;
	}
	while (cur && !cmp(cur->content, data))
	{
		prev = cur;
		cur = next;
		next = cur->next;
	}
	if (cur)
	{
		ft_lstdelone(&cur, del);
		prev->next = next;
	}
}
