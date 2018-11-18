/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qslist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:24:36 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/18 14:17:26 by oevtushe         ###   ########.fr       */
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
** Sort a list using quick sort algorithm
*/

void		ft_qslist(t_list **lst, int (*cmp)(void *, void *))
{
	int		size;
	void	**arr;

	size = ft_lstlen(*lst);
	arr = ft_lsttoarr(*lst);
	ft_qsarr(arr, 0, size - 1, cmp);
	ft_lstdel(lst, del_simple);
	*lst = ft_arrtolst(arr, size);
	free(arr);
}
