/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argsparser_ti.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 10:18:48 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/18 14:54:01 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	parse_arg(char *arg, void *container, int len,
			int (*set_option)(void *container, char option))
{
	int	j;

	j = 1;
	while (j < len && set_option(container, arg[j]))
		++j;
	return (j);
}

static int	cases(char *str, t_pos *pos, void *container,
				int (*set_option)(void *container, char option))
{
	int		len;

	len = (int)ft_strlen(str);
	if (len == 2 && str[0] == '-' && str[1] == '-')
	{
		++pos->y;
		return (3);
	}
	if (str[0] != '-' || len == 1)
		return (2);
	if (len > 1 && (pos->x = parse_arg(str,
					container, len, set_option)) != len)
		return (0);
	return (-1);
}

/*
** @See ft_argsparser
**
** States of sz_vld:
**
**		-1 -> argv is NULL
**		0  -> invalid option passed
** 		1  -> every element in argv is valid option
** 		2  -> not an option
** 		3  -> first element after '--' (end of the options list)
*/

t_pos		ft_argsparser_ti(char **argv, int *sz_vld, void *container,
				int (*set_option)(void *container, char option))
{
	int		tmp;
	t_pos	pos;

	pos.y = 0;
	if (argv)
	{
		while (pos.y < *sz_vld)
		{
			pos.x = 0;
			if ((tmp = cases(argv[pos.y], &pos,
							container, set_option)) != -1)
			{
				*sz_vld = tmp;
				return (pos);
			}
			++pos.y;
		}
		*sz_vld = 1;
	}
	else
		*sz_vld = -1;
	return (pos);
}
