/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_readers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:59 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/19 19:41:19 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Read data (width/precision/data) index from @param str
**
** @param	str		string to read from.
** @param	idx		index at @param str where data index
**					starting from.
** @return			data index.
** @return	-1		if there no data index, or data index is to small.
*/

int		read_data_index(const char *str, size_t *idx)
{
	int		i;
	int		val;

	i = *idx;
	val = -1;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			++i;
		if (str[i] == '$')
		{
			val = ft_atoi(&str[*idx]);
			if (val > 0)
				*idx = ++i;
		}
	}
	return (val);
}

void	read_width(const char *str, size_t *idx)
{
	int i;

	i = *idx;
	if (ft_isdigit(str[i]))
	{
		while (ft_isdigit(str[i]))
			++i;
		*idx = i;
	}
	else if (str[i] == '*')
	{
		*idx = ++i;
		read_data_index(str, idx);
	}
}

void	read_flags(const char *str, size_t *idx)
{
	int i;

	i = *idx;
	while (str[i] == '+' || str[i] == '-'
			|| str[i] == ' ' || str[i] == '0' ||
				str[i] == '#' || str[i] == '\'')
		++i;
	*idx = i;
}

void	read_precision(const char *str, size_t *idx)
{
	if (str[*idx] == '.')
	{
		++(*idx);
		if (ft_isdigit(str[*idx]))
			while (ft_isdigit(str[*idx]))
				++(*idx);
		else if (str[*idx] == '*')
		{
			++(*idx);
			read_data_index(str, idx);
		}
	}
}

void	read_modifiers(const char *str, size_t *idx)
{
	if ((str[*idx] == 'l' && str[*idx + 1] == 'l') ||
			(str[*idx] == 'h' && str[*idx + 1] == 'h'))
		*idx += 2;
	else if (str[*idx] == 'z' || str[*idx] == 'j' ||
				(str[*idx] == 'h') || (str[*idx] == 'l'))
		*idx += 1;
}
