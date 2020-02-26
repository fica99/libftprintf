/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buff_managment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:17:18 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/26 21:54:30 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pf_add_width(t_printf *restrict pf, const size_t len)
{
	while ((pf->width)-- > len)
		pf->buff[(pf->buff_len)++] = (pf->flags & PF_FL_ZERO) ? '0' : ' ';
}

void			pf_add_char(t_printf *restrict pf, const char c)
{
	pf_check_mem(pf, pf->width + 1);
	if (pf->flags & PF_FL_MINUS)
	{
		pf->buff[(pf->buff_len)++] = c;
		pf_add_width(pf, 1);
	}
	else
	{
		pf_add_width(pf, 1);
		pf->buff[(pf->buff_len)++] = c;
	}
}

void			pf_check_mem(t_printf *restrict pf, const size_t add_len)
{
	while (pf->buff_len + add_len >= pf->malloc_len)
		if (!(pf->buff = ft_realloc((void*)pf->buff, pf->malloc_len,
				(pf->malloc_len *= 2))))
			exit(1);
}
