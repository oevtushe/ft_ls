/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstget_de.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:58:44 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/14 17:59:50 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list_de	*ft_lstget_de(t_list_de *lst, unsigned int idx)
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
