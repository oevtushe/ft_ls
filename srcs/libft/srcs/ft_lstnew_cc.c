/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_cc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:45:08 by oevtushe          #+#    #+#             */
/*   Updated: 2018/08/08 18:04:45 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function creates new node with specified content and
** content_size, but content won't be copied, it will
** point at passed one
**
** Suffix 'cc' means catch content
*/

t_list	*ft_lstnew_cc(void *content, size_t content_size)
{
	t_list *node;

	node = (t_list *)ft_memalloc(sizeof(t_list));
	if (node)
	{
		node->content = content;
		node->content_size = content_size;
	}
	return (node);
}
