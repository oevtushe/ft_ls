/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treelevellen.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:43:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/18 13:28:06 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_treelevellen(const t_tree *tree)
{
	size_t	len;

	len = 0;
	while (tree)
	{
		tree = tree->siblings;
		++len;
	}
	return (len);
}
