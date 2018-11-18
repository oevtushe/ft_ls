/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 12:03:03 by oevtushe          #+#    #+#             */
/*   Updated: 2017/11/16 17:18:26 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nlst;
	t_list *tmp;

	nlst = NULL;
	tmp = NULL;
	if (f && lst)
	{
		while (lst)
		{
			tmp = f(lst);
			if (tmp)
				ft_lstappend(&nlst, tmp);
			lst = lst->next;
		}
	}
	return (nlst);
}
