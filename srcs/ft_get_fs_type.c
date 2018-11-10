/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_fs_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:36:58 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/09 18:41:41 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/stat.h>
#include "ft_ls.h"

int		ft_get_fs_type(char *str)
{
	struct stat buf;

	if (!lstat(str, &buf))
	{
		if (S_ISDIR(buf.st_mode))
			return (1);
		else
			return (2);
	}
	else
		return (0);
}
