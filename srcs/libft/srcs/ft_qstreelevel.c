/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qstreelevel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:48:07 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/18 14:17:12 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	del_simple(void *content, size_t content_size)
{
	content = NULL;
	content_size = 0;
}

/*
** Sort tree level using quicksort
*/

void		ft_qstreelevel(t_tree **tree, int (*cmp)(void *, void *))
{
	int		size;
	void	**arr;

	size = ft_treelevellen(*tree);
	arr = ft_treeleveltoarr(*tree);
	ft_qsarr(arr, 0, size - 1, cmp);
	ft_treeleveldel(tree, del_simple);
	*tree = ft_arrtotreelevel(arr, size);
	free(arr);
}
