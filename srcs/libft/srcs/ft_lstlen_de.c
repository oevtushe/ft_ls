/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen_de.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:44:28 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/14 17:44:47 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstlen_de(const t_list_de *lst)
{
	size_t	len;

	len = 0;
	while (lst)
	{
		lst = lst->next;
		++len;
	}
	return (len);
}
