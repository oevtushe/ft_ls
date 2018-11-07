/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treeadd_kid.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:35:21 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/06 11:42:30 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	ft_treeadd_kid(t_tree **tree, t_tree *new)
{
	if (tree && *tree && new)
	{
		new->siblings = (*tree)->kids;
		(*tree)->kids = new;
	}
}
