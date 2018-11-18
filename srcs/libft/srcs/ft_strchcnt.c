/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchcnt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 16:39:24 by oevtushe          #+#    #+#             */
/*   Updated: 2018/07/23 19:20:27 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Function counts times specified character was met in the line
*/

int		ft_strchcnt(char *line, char c)
{
	int		cnt;

	cnt = 0;
	if (line)
	{
		while (*line)
		{
			if (*line == c)
				++cnt;
			++line;
		}
	}
	return (cnt);
}
