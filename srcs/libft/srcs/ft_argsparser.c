/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_argsparser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 15:07:28 by oevtushe          #+#    #+#             */
/*   Updated: 2018/11/10 11:22:12 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	parse_arg(char *arg, void *container, int len,
			int (*set_option)(void *container, char option))
{
	int		j;

	j = 0;
	while (++j < len)
		if (!set_option(container, arg[j]))
			return (0);
	return (j);
}

/*
** Function for program's options parsing.
** Options may be passed as '-a' '-r' etc..
** or combined '-ar' ...
**
** Notice:
** 		1. Pass only array with options, array mustn't contain
** 			first program argument (program name)
** 		2. Only single char allowed per option (no '-hh' option possible,
** 			because it'll be interpreted as '-h -h')
**
** @param	argv		array of arguments (without program name)
** @param	size		size of the array of arguments (without program name)
** @param	container	conteiner which will hold passed arguments
** @param	set_option	function which checks current option
** 						and sets this option to the container, if option is
** 						valid function returns 1, 0 otherwise.
** @return	1			if all options were valid
** 			0			if 1 or more options were invalid
*/

int			ft_argsparser(char **argv, int size, void *container,
				int (*set_option)(void *container, char option))
{
	int		i;
	int		j;
	int		len;
	int		res;

	i = 0;
	j = 0;
	len = 0;
	res = 0;
	if (argv)
	{
		while (i < size)
		{
			len = (int)ft_strlen(argv[i]);
			if (!(argv[i][0] == '-' && len > 1 &&
				(j = parse_arg(argv[i], container, len, set_option))))
				break ;
			++i;
		}
		if (i == size && j == len)
			res = 1;
	}
	return (res);
}
