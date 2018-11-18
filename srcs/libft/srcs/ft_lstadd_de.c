/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_de.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:33:56 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 12:17:09 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_de(t_list_de **alst, t_list_de *new)
{
	if (alst && new)
	{
		new->next = *alst;
		if (*alst)
			(*alst)->prev = new;
		*alst = new;
	}
}
