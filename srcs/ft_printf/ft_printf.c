/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:11:50 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/27 17:53:56 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_init_start(t_printf *pf)
{
	ft_bzero(pf, sizeof(*pf));
	pf->malloc_len = PRINTF_BUFF_SIZE;
	if (!(pf->buff = (char*)malloc(pf->malloc_len * sizeof(char))))
		exit(1);
}

int				ft_printf(const char *restrict format, ...)
{
	t_printf		pf;
	size_t			res;

	if (!format)
		return (0);
	pf_init_start(&pf);
	va_start(pf.argptr, format);
	while (format[pf.i])
		pf_parse_string(format, &pf);
	res = write(1, pf.buff, pf.buff_len);
	va_end(pf.argptr);
	ft_strdel(&pf.buff);
	return (res);
}
