/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_de.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/12 17:50:23 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/14 18:08:00 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list_de		*ft_lstnew_de(void const *content, size_t content_size)
{
	t_list_de	*node;

	node = (t_list_de*)malloc(sizeof(t_list_de));
	if (node)
	{
		if (content)
		{
			node->content = malloc(content_size);
			if (!node->content)
			{
				free(node);
				return (NULL);
			}
			ft_memcpy(node->content, content, content_size);
			node->content_size = content_size;
		}
		else
		{
			node->content_size = 0;
			node->content = NULL;
		}
		node->next = NULL;
		node->prev = NULL;
	}
	return (node);
}
