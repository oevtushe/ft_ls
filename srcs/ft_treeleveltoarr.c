/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeleveltoarr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:52:53 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/10 18:49:39 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*
** Function creates an array of pointers from data in tree content
**
** Notice: all content in list nodes has to have single type.
** The content won't be cloned.
*/

void	**ft_treeleveltoarr(t_tree *tree)
{
	int		idx;
	int		len;
	void	**arr;

	idx = 0;
	arr = NULL;
	if (tree)
	{
		len = ft_treelevellen(tree);
		arr = ft_memalloc(len * sizeof(void *));
		if (arr)
		{
			while (tree)
			{
				arr[idx++] = tree->content;
				tree = tree->siblings;
			}
		}
	}
	return (arr);
}
