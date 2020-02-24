/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:12:31 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/18 20:54:46 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include "libft.h"

# define PRINTF_BUFF_SIZE 10000

typedef struct	s_printf
{
	va_list		argptr;
	size_t		buff_len;
	char		buff[PRINTF_BUFF_SIZE + 1];

}				t_printf;

int				ft_printf(const char *str, ...);

#endif
