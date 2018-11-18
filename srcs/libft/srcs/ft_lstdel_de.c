/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel_de.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 18:00:51 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/14 18:09:49 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel_de(t_list_de **alst, void (*del)(void*, size_t))
{
	t_list_de *tmp;

	if (alst && del)
	{
		while (*alst)
		{
			tmp = *alst;
			*alst = (*alst)->next;
			del(tmp->content, tmp->content_size);
			ft_memdel((void **)&tmp);
		}
	}
}
