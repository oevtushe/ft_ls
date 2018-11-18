/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newpair_cc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/06 10:32:37 by oevtushe          #+#    #+#             */
/*   Updated: 2018/08/06 10:34:13 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_pair	*ft_newpair_cc(void *fst, void *scd)
{
	t_pair	*pair;

	pair = (t_pair *)ft_memalloc(sizeof(t_pair));
	if (pair)
	{
		pair->fst = fst;
		pair->scd = scd;
	}
	return (pair);
}
