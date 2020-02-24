/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:11:50 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/24 19:24:10 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static size_t	pf_parse_args(char *str, size_t pos, t_printf *pf)
// {

// 	return (pos);
// }

int				ft_printf(const char *str, ...)
{
	t_printf	pf;
	size_t		res;
	size_t		i;

	ft_bzero(&pf, sizeof(pf));
	va_start(pf.argptr, str);
	i = 0;
	while (str[i])
	{
		// if (str[i] == '%')
		// 	i = pf_parse_args(str, i + 1, &pf);
		// else
			pf.buff[pf.buff_len++] = str[i];
		++i;
	}
	res = write(1, pf.buff, pf.buff_len);
	va_end(pf.argptr);
	return (res);
}
