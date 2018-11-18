/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:46:41 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/18 14:16:56 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_treedel(t_tree **tree,
			void (*del)(void *content, size_t content_size))
{
	t_tree	*tmp;

	if (tree)
	{
		while (*tree)
		{
			ft_treedel(&(*tree)->kids, del);
			del((*tree)->content, (*tree)->content_size);
			tmp = *tree;
			*tree = (*tree)->siblings;
			free(tmp);
		}
	}
}
