/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arr_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:48:11 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:48:12 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Get max index inside @param str.
**
** @param	str		string index is searching in.
** @return			max index founded in @param str.
** @return	-1		if str doesn't contain any indexes.
*/

static int	get_str_max_idx(const char *str)
{
	size_t	i;
	int		cur_max;
	int		tmp;
	char	*pos;

	i = 1;
	cur_max = read_data_index(str, &i);
	while ((pos = ft_strchr(&str[i], '*')))
	{
		i = pos - str;
		++i;
		tmp = read_data_index(str, &i);
		cur_max = (tmp > cur_max) ? tmp : cur_max;
	}
	return (cur_max);
}

/*
** Count how much data @param str need.
**
** @param	str		string to count in.
** @return			count of data @param str need.
*/

static int	count_idx(const char *str)
{
	char	*pos;
	int		idx;
	int		prev;

	idx = 1;
	prev = 0;
	while ((pos = ft_strchr(&str[prev], '*')))
	{
		++idx;
		prev = pos - str + 1;
	}
	return (idx);
}

/*
** Count how much data @param extra list need in case
** of dollar logic.
**
** @param	extra	list to count in.
** @return			count of data @param extra need.
*/

static int	get_arr_size_dl(t_list *extra)
{
	int		max;
	int		tmp;
	char	*cur;

	max = 0;
	while (extra)
	{
		cur = extra->content;
		if (cur[ft_strlen(cur) - 1])
		{
			tmp = get_str_max_idx(cur);
			max = (tmp > max) ? tmp : max;
			extra = extra->next;
		}
	}
	return (max);
}

/*
** Count how much data @param extra list need in case
** of simple logic.
**
** @param	extra	list to count in.
** @return			count of data @param extra need.
*/

static int	get_arr_size_smp(t_list *extra)
{
	int		max;
	char	*cur;

	max = 0;
	while (extra)
	{
		cur = extra->content;
		if (cur[ft_strlen(cur) - 1])
			max += count_idx(cur);
		extra = extra->next;
	}
	return (max);
}

/*
** Calculates data arr size.
**
** @param	extra	list with format strings data arr
** 					size is calculateing from.
** @param	lt		logic type (dollar -> "%1$d"/simple -> "%d")
*/

int			get_arr_size(t_list *extra, int lt)
{
	int		max;

	if (lt)
		max = get_arr_size_dl(extra);
	else
		max = get_arr_size_smp(extra);
	return (max);
}
