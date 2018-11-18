/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utu8.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 20:53:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/02/24 20:53:26 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <wchar.h>
#include "ft_printf_helpers.h"

/*
** Counts bit count in @param val.
** If value is negative - ignore it.
**
** @param	val		value to count bits in.
*/

static int			bit_cnt(wchar_t val)
{
	int		cnt;

	cnt = 0;
	while (val && val > 0)
	{
		++cnt;
		val >>= 1;
	}
	return (cnt);
}

/*
** Makes a tail of utf8 byte sequence.
** For example tail of 4 byte sequence in utf8 is
** 00xxxxxx 00xxxxxx 00xxxxxx, of 2 byte seq. is
** 00xxxxxx and so on., where x -> tail elements.
**
** @param	val		value to get tail of.
** @param	bp		tail length. For example in
**					4 byte seq. bp equals 3, etc.
*/

static unsigned int	get_tail(wint_t val, unsigned int bp)
{
	int						bi;
	unsigned int			tmp;
	unsigned int			res;

	bi = sizeof(int) * 8;
	res = 0;
	tmp = val;
	if (bp > 0)
	{
		while (bp--)
		{
			tmp >>= 6 * bp;
			tmp = (tmp << (bi - 6)) >> (bi - 6);
			tmp <<= 8 * bp;
			res |= tmp;
			tmp = val;
		}
	}
	return (res);
}

/*
** Convert wint_t value to utf8 byte sequence.
**
** Masks:
**	   0xC080 	  -> 110xxxxx 10xxxxxx
**	   0xE08080   -> 1110xxxx 10xxxxxx 10xxxxxx
**	   0xF0808080 -> 11110xxx 10xxxxxx 10xxxxxx 10xxxxxx
**
** @param	val		value to be converted.
** @return			utf8 byte sequence.
*/

wint_t				ft_utu8(wint_t val)
{
	wint_t		res;
	int			bc;
	size_t		bi;

	bi = sizeof(wint_t) * 8;
	bc = bit_cnt(val);
	res = 0;
	if (bc <= 7)
		return (val);
	if (bc > 16 && bc <= 21)
	{
		res = get_tail(val, 3) | 0xF0808080;
		res |= (unsigned int)((val >> 18) << (bi - 3)) >> (bi - 27);
	}
	else if (bc > 11 && bc <= 16)
	{
		res = get_tail(val, 2) | 0xE08080;
		res |= (unsigned int)((val >> 12) << (bi - 4)) >> (bi - 20);
	}
	else if (bc > 7 && bc <= 11)
	{
		res = get_tail(val, 1) | 0xC080;
		res |= (unsigned int)((val >> 6) << (bi - 5)) >> (bi - 13);
	}
	return (res);
}
