/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:59:01 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/18 13:31:20 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

/*
** Create a new tree node
** Copy content using passed in arguments funtion
*/

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
