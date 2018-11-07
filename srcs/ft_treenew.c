/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:34:52 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/06 11:44:28 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ls.h"

t_tree		*ft_treenew(void *content, size_t content_size)
{
	t_tree	*node;

	node = (t_tree*)ft_memalloc(sizeof(t_tree));
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
	}
	return (node);
}
