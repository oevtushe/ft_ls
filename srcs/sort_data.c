/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 18:54:16 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/13 18:55:10 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_list(t_options *ops, t_list **data)
{
	if (ops->r && ops->t)
		ft_qslist(data, cmp_rentries_t);
	else if (ops->r)
		ft_qslist(data, cmp_rentries);
	else if (ops->t)
		ft_qslist(data, cmp_entries_t);
	else
		ft_qslist(data, cmp_entries);
}
