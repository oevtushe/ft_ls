/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 14:46:41 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/17 19:45:01 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ls.h"

void	ft_treedel(t_tree **tree, void (*del)(void *content, size_t content_size))
{
	t_entry *ent;
	t_tree	*tmp;

	if (tree)
	{
		while (*tree)
		{
			ent = (t_entry *)(*tree)->content;
			ft_treedel(&(*tree)->kids, del);
			del((*tree)->content, (*tree)->content_size);
			tmp = *tree;
			*tree = (*tree)->siblings;
			free(tmp);
		}
	}
}
