/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstappend_de.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/14 17:42:22 by oevtushe          #+#    #+#             */
/*   Updated: 2018/05/15 17:35:42 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstappend_de(t_list_de **lst, t_list_de *new)
{
	t_list_de *runner;

	if (lst)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		runner = *lst;
		while (runner->next)
			runner = runner->next;
		runner->next = new;
		new->prev = runner;
	}
}
