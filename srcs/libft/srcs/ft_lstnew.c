/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 14:28:39 by oevtushe          #+#    #+#             */
/*   Updated: 2017/12/24 13:17:33 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list*)malloc(sizeof(t_list));
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
	}
	return (node);
}
