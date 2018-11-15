/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_entrynew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 18:18:32 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/12 18:32:41 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ls.h"

t_entry	*ft_entrynew(char *name, char *full_path)
{
	t_entry *entry;

	entry = (t_entry *)malloc(sizeof(t_entry));
	if (entry)
	{
		entry->name = ft_strdup(name);
		entry->full_path = ft_strdup(full_path);
	}
	return (entry);
}
