/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treenew_cc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 17:12:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/10 18:48:54 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Function creates new node with specified content and
** content_size, but content won't be copied, it will
** point at passed one
**
** Suffix 'cc' means catch content
*/

t_tree	*ft_treenew_cc(void *content, size_t content_size)
{
	t_tree *node;

	node = (t_tree *)ft_memalloc(sizeof(t_tree));
	if (node)
	{
		node->content = content;
		node->content_size = content_size;
	}
	return (node);
}
