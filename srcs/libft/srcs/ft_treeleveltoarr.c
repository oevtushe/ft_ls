/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeleveltoarr.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:52:53 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/18 13:26:45 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Function creates an array of pointers from data in tree level (siblings)
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
