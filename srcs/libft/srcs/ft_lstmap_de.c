/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_de.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:38:09 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/15 17:35:29 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_de	*ft_lstmap_de(t_list_de *lst, t_list_de *(*f)(t_list_de *elem))
{
	t_list_de *nlst;
	t_list_de *tmp;

	nlst = NULL;
	tmp = NULL;
	if (f && lst)
	{
		while (lst)
		{
			tmp = f(lst);
			if (tmp)
				ft_lstappend_de(&nlst, tmp);
			lst = lst->next;
		}
	}
	return (nlst);
}
