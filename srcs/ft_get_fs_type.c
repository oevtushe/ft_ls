/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fs_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:36:58 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/07 10:37:07 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_get_fs_type(char *str)
{
	DIR	*dir;

	if ((dir = opendir(str)) == NULL)
	{
		if (errno == ENOTDIR)
			return (1);
		else if (errno == ENOENT)
			return (2);
	}
	else
		closedir(dir);
	return (0);
}
