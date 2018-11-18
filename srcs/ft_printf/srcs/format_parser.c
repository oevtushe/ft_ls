/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_parser.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 12:47:49 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/18 12:47:50 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

/*
** Function read width from @param str or from @param gdata if '$' present.
**
** @param	str		string data to be readed from.
** @param	di		order index in the data array @param gdata.
** @param	idx		index in str to start reading from.
** @param	gdata	data array.
**
** @return			width based on @param str information.
*/

static int	get_width(const char *str, int *di, size_t *idx, t_gdata **gdata)
{
	size_t	width;

	width = 0;
	if (ft_isdigit(str[(*idx)]))
	{
		width = (size_t)ft_atoi(&(str[(*idx)]));
		while (ft_isdigit(str[(*idx)]))
			++(*idx);
	}
	else if (str[(*idx)] == '*')
	{
		++(*idx);
		width = outside_param(str, idx, gdata, di);
	}
	return (width);
}

/*
** Function read precision from @param str or from @param gdata. If '$' present
** def val = -1 in case this value doesn't collapse with none of explicit set.
**
** @param	str		string data to be readed from.
** @param	di		order index in the data array @param gdata.
** @param	idx		index in str to start reading from.
** @param	gdata	data array.
**
** @return			precision based on @param str information.
*/

static int	get_precision(const char *str, int *di, size_t *idx, t_gdata **gd)
{
	int precision;

	precision = -1;
	if (str[(*idx)] == '.')
	{
		precision = 0;
		++(*idx);
		if (str[(*idx)] == '*')
		{
			++(*idx);
			precision = outside_param(str, idx, gd, di);
		}
		else
		{
			precision = ft_atoi(&(str[(*idx)]));
			while (ft_isdigit(str[(*idx)]))
				++(*idx);
		}
	}
	return (precision);
}

static void	init_modifiers(const char *str, size_t *idx)
{
	int mdf;

	mdf = M_DEFAULT;
	if (str[*idx] == 'l' && str[*idx + 1] == 'l')
		mdf = M_LL;
	else if (str[*idx] == 'l')
		mdf = M_L;
	else if (str[*idx] == 'h' && str[*idx + 1] == 'h')
		mdf = M_HH;
	else if (str[*idx] == 'h')
		mdf = M_H;
	else if (str[*idx] == 'j')
		mdf = M_J;
	else if (str[*idx] == 'z')
		mdf = M_Z;
	if (mdf == M_HH || mdf == M_LL)
		*idx += 2;
	else if (mdf == M_L || mdf == M_H || mdf == M_J || mdf == M_Z)
		(*idx)++;
}

static void	init_flags(const char *str, t_format *cf, size_t *idx)
{
	while (str[*idx])
	{
		if (str[*idx] == '+')
			cf->flag_plus = 1;
		else if (str[*idx] == '-')
			cf->flag_minus = 1;
		else if (str[*idx] == ' ')
			cf->flag_space = 1;
		else if (str[*idx] == '0')
			cf->flag_zero = 1;
		else if (str[*idx] == '#')
			cf->flag_sharp = 1;
		else if (str[*idx] == '\'')
			cf->flag_squote = 1;
		else
			break ;
		++(*idx);
	}
}

/*
** Function initialise t_format structure by data
** explicit given in @param str or load it from @param gdata
** by index given in the string.
**
** @param	str		format string.
** @param	di		order index in case of simple logic.
** @param	gdata	data array based on va_list.
** @param	lt		logic type (dollar or simple).
**
** @return			initialized t_format object.
*/

t_format	*format_parser(const char *str, int *di, t_gdata **gdata, int lt)
{
	size_t		idx;
	t_format	*cur_format;

	idx = 1;
	cur_format = (t_format *)ft_memalloc(sizeof(t_format));
	if (lt)
		cur_format->gdata = get_cur_data(str, &idx, di, gdata);
	init_flags(str, cur_format, &idx);
	cur_format->width = get_width(str, di, &idx, gdata);
	cur_format->precision = get_precision(str, di, &idx, gdata);
	if (!lt)
		cur_format->gdata = get_cur_data(str, &idx, di, gdata);
	init_modifiers(str, &idx);
	normalize_width(cur_format);
	return (cur_format);
}
