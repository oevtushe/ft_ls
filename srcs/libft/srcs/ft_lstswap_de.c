/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap_de.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 18:00:10 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/14 18:01:24 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap_de(t_list_de *lst, unsigned int p1, unsigned int p2)
{
	t_list_de	*fst;
	t_list_de	*scd;
	void		*tc;
	size_t		ts;

	fst = ft_lstget_de(lst, p1);
	scd = ft_lstget_de(lst, p2);
	if (fst && scd && fst != scd)
	{
		tc = fst->content;
		ts = fst->content_size;
		fst->content = scd->content;
		scd->content = tc;
		fst->content_size = scd->content_size;
		scd->content_size = ts;
	}
}
