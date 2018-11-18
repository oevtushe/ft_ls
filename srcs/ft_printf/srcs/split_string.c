/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:55 by oevtushe          #+#    #+#             */
/*   Updated: 2018/03/10 10:41:51 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Find valid format string in @param str
** start from @param start.
**
** @param	str			string format is searching in.
** @param	start		index in string format is searching from.
** @param	end			index to end of format string.
** @return				format string if found, also @param start and @param end
** 						initialized to start and end of format
**						string respectively.
** @return	NULL		if no more valid format string in @param str.
*/

static char	*find_format(const char *str, size_t *start, size_t *end)
{
	char	*tmp;
	char	*res;
	size_t	pos;

	res = NULL;
	pos = *start;
	while ((tmp = ft_strchr(&str[pos], '%')))
	{
		pos = tmp - str;
		if ((res = get_format_string(str, &pos)))
		{
			*start = tmp - str;
			*end = pos;
			break ;
		}
		++pos;
	}
	return (res);
}

/*
** Fills lists of format and simple data strings.
**
** Invalid format strings will be interpretated as
** simple text.
**
** @param	plain	list with simple text.
** @param	extra	list with validated format strings.
*/

void		split_string(const char *str, t_list **plain, t_list **format)
{
	size_t		start;
	size_t		end;
	size_t		prev;
	char		*tmp;

	start = 0;
	end = 0;
	prev = 0;
	while ((tmp = find_format(str, &start, &end)))
	{
		ft_lstaddelem(format, (void**)(&tmp), ft_strlen(tmp) + 1);
		tmp = ft_strsub(str, prev, start - prev);
		ft_lstaddelem(plain, (void**)(&tmp), ft_strlen(tmp) + 1);
		prev = end;
		start = end;
	}
	if (prev < ft_strlen(str))
	{
		tmp = ft_strsub(str, prev, ft_strlen(str) - prev);
		ft_lstaddelem(plain, (void**)(&tmp), ft_strlen(tmp) + 1);
	}
	validate_lists(str, plain, format);
}
