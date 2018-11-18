/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/17 11:06:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/07/23 19:16:06 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function returns the data of the last element in the list and deletes the
** node
**
** @return	data of the last element of the list
*/

void	*ft_lstpop(t_list **lst)
{
	t_list	*last;
	t_list	*runner;
	void	*data;

	runner = *lst;
	data = NULL;
	if (lst && *lst)
	{
		if ((*lst)->next)
		{
			while (runner->next->next)
				runner = runner->next;
			last = runner->next;
			data = last->content;
			runner->next = NULL;
		}
		else
		{
			last = *lst;
			data = last->content;
			*lst = NULL;
		}
		ft_memdel((void**)&last);
	}
	return (data);
}
