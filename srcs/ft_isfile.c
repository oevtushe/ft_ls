/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isfile.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:35:43 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/07 10:35:49 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		ft_isfile(char *str)
{
	DIR	*dir;

	if ((dir = opendir(str)) == NULL)
	{
		if (errno == ENOTDIR)
			return (1);
	}
	else
		closedir(dir);
	return (0);
}
