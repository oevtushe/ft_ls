/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 12:17:36 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 12:17:40 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_words(const char *str)
{
	int	wc;
	int	state;

	wc = 0;
	state = 0;
	if (str)
	{
		while (*str)
		{
			if (*str == ' ' || *str == '\t')
				state = 0;
			else if (!state)
			{
				state = 1;
				++wc;
			}
			++str;
		}
	}
	return (wc);
}
