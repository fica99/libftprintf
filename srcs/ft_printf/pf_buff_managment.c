/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_buff_managment.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:17:18 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/27 18:33:24 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_add_width(t_printf *restrict pf, const size_t len)
{
	while ((pf->width)-- > len)
		pf->buff[(pf->buff_len)++] = (pf->flags & PF_FL_ZERO) ? '0' : ' ';
}

static void		pf_add_str_2_buff(t_printf *restrict pf, const char *str,
														const size_t len)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] && i < len)
		pf->buff[pf->buff_len++] = str[i++];
}

void			pf_add_str(t_printf *restrict pf, const char *str)
{
	size_t	len;

	len = ft_strlen(str);
	if (pf->prec >= 0)
		len = pf->prec;
	pf_check_mem(pf, pf->width + len);
	if (pf->flags & PF_FL_MINUS)
	{
		pf_add_str_2_buff(pf, str, len);
		pf_add_width(pf, len);
	}
	else
	{
		pf_add_width(pf, len);
		pf_add_str_2_buff(pf, str, len);
	}
}

void			pf_check_mem(t_printf *restrict pf, const size_t add_len)
{
	while (pf->buff_len + add_len >= pf->malloc_len)
		if (!(pf->buff = ft_realloc((void*)pf->buff, pf->malloc_len,
				(pf->malloc_len *= 2))))
			exit(1);
}
