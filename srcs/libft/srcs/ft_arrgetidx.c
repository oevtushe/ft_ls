/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrgetidx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 18:16:19 by oevtushe          #+#    #+#             */
/*   Updated: 2018/08/08 18:20:05 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function returns an idx of searched data
** Comparison is made by function @param check
**
** check function has to return 1 if elements is equall, 0 otherwise
** @return		1 if @param data is present in @param arr
**				0 otherwise
*/

int		ft_arrgetidx(void **arr, int size, void *data,
			int (*check)(void *elem, void *data))
{
	int i;

	i = 0;
	if (arr && check)
	{
		while (i < size)
		{
			if (check(arr[i], data))
				return (i);
			++i;
		}
	}
	return (-1);
}
