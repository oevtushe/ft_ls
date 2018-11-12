/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeleveldel.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:54:26 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/10 16:56:02 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

void	ft_treeleveldel(t_tree **tree, void (*del)(void*, size_t))
{
	t_tree *tmp;

	if (tree && del)
	{
		while (*tree)
		{
			tmp = *tree;
			*tree = (*tree)->siblings;
			del(tmp->content, tmp->content_size);
			ft_memdel((void **)&tmp);
		}
	}
}
