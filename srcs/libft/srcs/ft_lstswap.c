/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 08:58:53 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/23 09:20:41 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstswap(t_list *lst, unsigned int p1, unsigned int p2)
{
	t_list	*fst;
	t_list	*scd;
	void	*tc;
	size_t	ts;

	fst = ft_lstget(lst, p1);
	scd = ft_lstget(lst, p2);
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
