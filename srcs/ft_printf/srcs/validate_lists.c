/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_lists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 13:17:55 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/21 13:17:57 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Another level of validation.
** For cases like "%3$.*d"
*/

static int	vldmi(const char *str)
{
	char	*pos;

	if (ft_strchr(str, '$'))
		if ((pos = ft_strchr(str, '*')))
			if (!ft_isdigit(*(pos + 1)))
				return (0);
	return (1);
}

static void	fatal_err_handler(const char *str, t_list **plain, t_list **format)
{
	ft_lstdel(plain, del_simple);
	ft_lstdel(format, del_simple);
	*plain = ft_lstnew(str, ft_strlen(str) + 1);
}

/*
** Validates mixed index cases.
** Example of mixed index: '%d text %1$d'.
** Here we have explicit seted index and order based.
** If this situation have place in @param extra content
** whole string will be interpretated as simple text.
**
** @param	format		whole format string.
** @param	plain		list of plain strings in @param format.
** @param	extra		list of only format strings in @param format.
*/

void		validate_lists(const char *format, t_list **plain, t_list **extra)
{
	int		lt;
	int		error;
	t_list	*tmp;
	char	*str;

	error = 0;
	tmp = *extra;
	lt = -1;
	while (tmp)
	{
		str = tmp->content;
		if (str[ft_strlen(str) - 1] != '%')
		{
			if (lt == -1)
				lt = ft_strchr(str, '$') ? 1 : 0;
			if (!vldmi(str) || lt != (ft_strchr(str, '$') ? 1 : 0))
			{
				error = 1;
				break ;
			}
		}
		tmp = tmp->next;
	}
	if (error)
		fatal_err_handler(format, plain, extra);
}
