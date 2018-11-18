/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lsttoarr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 13:49:40 by oevtushe          #+#    #+#             */
/*   Updated: 2018/08/08 18:05:03 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function creates an array of pointers from data in list content
**
** Notice: all content in list nodes has to have single type.
** The content won't be cloned.
*/

void	**ft_lsttoarr(t_list *lst)
{
	int		idx;
	int		len;
	void	**arr;

	idx = 0;
	arr = NULL;
	if (lst)
	{
		len = ft_lstlen(lst);
		arr = ft_memalloc(len * sizeof(void *));
		if (arr)
		{
			while (lst)
			{
				arr[idx++] = lst->content;
				lst = lst->next;
			}
		}
	}
	return (arr);
}
