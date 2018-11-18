/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstaddelem.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:42:32 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/10 15:45:58 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf_helpers.h"

/*
** Add element at list then free that element.
**
** @param	lst				list element be added to.
** @param	content			content of a new element.
** @param	content_size	content size of a new element.
*/

void	ft_lstaddelem(t_list **lst, void **content, size_t content_size)
{
	t_list	*new_elem;

	new_elem = ft_lstnew(*content, content_size);
	ft_lstappend(lst, new_elem);
	ft_memdel(content);
}
