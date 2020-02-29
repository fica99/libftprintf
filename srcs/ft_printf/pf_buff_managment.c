/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buff_managment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:17:18 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/29 20:17:44 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		pf_add_width(t_printf *restrict pf, const size_t len,
															const char symb)
{
	while ((pf->width)-- > len)
		pf->buff[(pf->buff_len)++] = symb;
}

void		pf_add_str_2_buff(t_printf *restrict pf, const char *str,
														const size_t len)
{
	size_t	i;

	i = 0;
	while (str[i] && i < len)
		pf->buff[pf->buff_len++] = str[i++];
}

void		pf_add_str(t_printf *restrict pf, char *str)
{
	size_t	len;

	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	pf_check_mem(pf, pf->width + len);
	if (pf->prec >= 0 && len > (size_t)pf->prec)
		len = pf->prec;
	if (pf->flags & PF_FL_MINUS)
	{
		pf_add_str_2_buff(pf, str, len);
		pf_add_width(pf, len, ' ');
	}
	else
	{
		pf_add_width(pf, len, pf->flags & PF_FL_ZERO ? '0' : ' ');
		pf_add_str_2_buff(pf, str, len);
	}
}

void		pf_check_mem(t_printf *restrict pf, const size_t add_len)
{
	while (pf->buff_len + add_len >= pf->malloc_len)
		if (!(pf->buff = ft_realloc((void*)pf->buff, pf->malloc_len,
				(pf->malloc_len *= 2))))
			exit(1);
}
