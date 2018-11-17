/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:59:01 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/17 20:05:22 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ls.h"

t_tree		*ft_treenew_spec(void *content, size_t content_size,
		void *(*dup_content)(void *content))
{
	t_tree	*node;

	node = (t_tree*)ft_memalloc(sizeof(t_tree));
	if (node)
	{
		if (content)
		{
			node->content = dup_content(content);
			if (!node->content)
			{
				free(node);
				return (NULL);
			}
			node->content_size = content_size;
		}
	}
	return (node);
}
