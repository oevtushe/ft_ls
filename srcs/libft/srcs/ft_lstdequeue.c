/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdequeue.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 19:54:44 by oevtushe          #+#    #+#             */
/*   Updated: 2018/07/23 19:44:19 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function removes first element from the list
** and returns its content
**
** @return	content of the first element
*/

void	*ft_lstdequeue(t_list **root)
{
	t_list	*fst;
	void	*content;

	content = NULL;
	if (root && *root)
	{
		fst = *root;
		*root = (*root)->next;
		content = fst->content;
		ft_memdel((void **)&fst);
	}
	return (content);
}
