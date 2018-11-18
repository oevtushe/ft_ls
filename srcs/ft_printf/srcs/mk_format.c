/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mk_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/08 18:22:08 by oevtushe          #+#    #+#             */
/*   Updated: 2018/08/08 18:22:09 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_helpers.h"

static char	*mngr_usr(t_format *sfmt, t_mng_dpc **dispatcher, size_t *fmt_len)
{
	int		i;
	char	*res;

	i = -1;
	res = NULL;
	while (++i < DISPATCHER_SIZE)
	{
		if (dispatcher[i]->type == sfmt->gdata->full_type->type)
		{
			res = dispatcher[i]->manager(sfmt, fmt_len);
			break ;
		}
	}
	return (res);
}

static char	*maker(t_list *pl, t_list *ex, size_t *len)
{
	char		*str;
	char		*extra_str;
	size_t		extra_len;
	t_mng_dpc	**dispatcher;

	str = ft_strnew(0);
	dispatcher = get_manager_dispatcher();
	while (ex)
	{
		extra_str = mngr_usr(ex->content, dispatcher, &extra_len);
		ft_memct((void**)&str, *len, pl->content, ft_strlen(pl->content) + 1);
		*len += ft_strlen(pl->content);
		ft_memct((void**)&str, *len, extra_str, extra_len);
		*len += extra_len;
		pl = pl->next;
		ex = ex->next;
		ft_memdel((void **)&extra_str);
	}
	if (pl)
	{
		ft_memct((void**)&str, *len, pl->content, ft_strlen(pl->content) + 1);
		*len += ft_strlen(pl->content);
	}
	del_void_ptr_arr((void***)&dispatcher);
	return (str);
}

/*
** Function changes content of @param extra list from format strings
** to t_format objects.
**
** @param	extra	list to be changed.
** @param	gdata	array of data based on va_list and information in
**					format string.
** @param	lt		logic type (dollar or simple).
*/

static void	reformat_extra(t_list *extra, t_gdata **gdata, int lt)
{
	int			di;
	t_format	*sfmt;

	di = 0;
	while (extra)
	{
		sfmt = format_parser((char *)extra->content, &di, gdata, lt);
		free(extra->content);
		extra->content = sfmt;
		extra->content_size = sizeof(t_format);
		extra = extra->next;
	}
}

/*
** Function makes string based on format specified in @param format
** and data in va_list @param ap.
**
** @param	format	format string.
** @param	ap		list of data.
** @param	len		length of result string.
**
** @return			string or char array based on format in @param format
**					and data in @param ap.
*/

char		*mk_format(const char *format, va_list ap, size_t *len)
{
	int		lt;
	char	*str;
	t_list	*plain;
	t_list	*extra;
	t_gdata	**gdata;

	plain = NULL;
	extra = NULL;
	split_string(format, &plain, &extra);
	lt = logic_type(extra);
	gdata = get_data_arr(extra, ap, lt);
	reformat_extra(extra, gdata, lt);
	str = maker(plain, extra, len);
	ft_lstdel(&plain, del_simple);
	del_gdata_arr(&gdata);
	ft_lstdel(&extra, del_extra);
	return (str);
}
