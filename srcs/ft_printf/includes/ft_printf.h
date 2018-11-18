/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oevtushe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 19:49:38 by oevtushe          #+#    #+#             */
/*   Updated: 2018/08/08 18:26:50 by oevtushe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FT_PRINTF_H
# define _FT_PRINTF_H

# include <strings.h>

/*
** Special options for pretty.
*/

# define BOLD "\033[1m"
# define DBOLD "\033[2m"
# define NBOLD "\033[22m"
# define UNDERLINE "\033[4m"
# define NUNDERLINE "\033[4m"
# define INVERSE "\033[7m"
# define NINVERSE "\033[7m"
# define RESET "\033[m"

/*
** Text colors.
*/

# define BLACK "\033[30m"
# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define MAGENTA "\033[35m"
# define CYAN "\033[36m"
# define GRAY "\033[37m"
# define ORANGE "\033[38;5;214m"

/*
** Background colors.
*/

# define BGBLACK "\033[40m"
# define BGRED "\033[41m"
# define BGGREEN "\033[42m"
# define BGBROWN "\033[43m"
# define BGBLUE "\033[44m"
# define BGMAGENTA "\033[45m"
# define BGCYAN "\033[46m"
# define BGGRAY "\033[47m"
# define BGDEF "\033[49m"

int		ft_printf(const char *format, ...);
char	*ft_format(const char *format, size_t *len, ...);

#endif
