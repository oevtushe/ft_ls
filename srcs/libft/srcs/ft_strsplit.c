/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 08:48:55 by oevtushe          #+#    #+#             */
/*   Updated: 2018/06/07 12:12:40 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

static int	count_blocks(const char *str, char c)
{
	int		wc;
	int		state;

	state = 0;
	wc = 0;
	while (*str)
	{
		if (*str == c)
			state = 0;
		else if (!state)
		{
			state = 1;
			++wc;
		}
		++str;
	}
	return (wc);
}

static void	clear_arr(char ***wa)
{
	int	idx;

	idx = -1;
	if (wa != NULL)
	{
		while ((*wa)[++idx])
			free((*wa)[idx]);
		free(*wa);
		*wa = NULL;
	}
}

static int	safety_add(char **wa, int *wa_idx, int end, const char *str)
{
	char	*sub;

	sub = ft_strsub(str, 0, end);
	if (sub)
	{
		wa[(*wa_idx)++] = sub;
	}
	else
		clear_arr(&wa);
	return ((sub) ? 1 : 0);
}

char		**ft_strsplit(char const *str, char c)
{
	int		i;
	int		start;
	int		wa_idx;
	char	**wa;

	i = count_blocks(str, c);
	wa = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	if (wa)
	{
		i = -1;
		wa_idx = 0;
		while (str[++i])
			if (str[i] != c)
			{
				start = i;
				while (str[i] && str[i] != c)
					++i;
				if (!safety_add(wa, &wa_idx, i - start, &str[start]))
					return ((void*)0);
				if (!str[i])
					break ;
			}
	}
	return (wa);
}
