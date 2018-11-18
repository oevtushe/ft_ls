/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 13:59:02 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/18 14:02:36 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_ls.h"

void	delentry(void *content, size_t content_size)
{
	t_entry *ent;

	content_size = 0;
	ent = (t_entry *)content;
	free(ent->name);
	free(ent->full_path);
	free(ent);
}

void	*dup_content(void *content)
{
	t_entry *ent;
	t_entry *new;

	new = ft_memalloc(sizeof(t_entry));
	ent = (t_entry *)content;
	new->name = ft_strdup(ent->name);
	new->full_path = ft_strdup(ent->full_path);
	return (new);
}

int		set_option(void *container, char option)
{
	int			*i;
	t_options	*p;

	i = NULL;
	p = (t_options *)container;
	if (option == 'a')
		i = &p->a;
	else if (option == 'R')
		i = &p->ur;
	else if (option == 'l')
		i = &p->l;
	else if (option == 'r')
		i = &p->r;
	else if (option == 't')
		i = &p->t;
	if (i)
		*i = 1;
	return (i ? 1 : 0);
}
