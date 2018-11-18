/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 09:09:00 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/23 09:18:59 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstget(t_list *lst, unsigned int idx)
{
	unsigned int i;

	i = 0;
	while (lst && i < idx)
	{
		++i;
		lst = lst->next;
	}
	return (lst);
}
