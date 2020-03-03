/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 21:11:00 by ggrimes           #+#    #+#             */
/*   Updated: 2020/03/03 22:01:56 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_check_prefix(t_printf *restrict pf)
{
	if (pf->flags & PF_FL_HASH)
	{
		ft_memcpy(pf->buff + pf->buff_len, "0x", 2);
		pf->buff_len += 2;
	}
}

static size_t	pf_pre_x(t_printf *restrict pf, intmax_t nb, size_t len)
{
	char		sign;
	size_t		res_len;
	char		is_prec;

	if ((int)len < pf->prec || (!pf->prec && !nb))
		res_len = pf->prec;
	else
		res_len = len;
	if (pf->flags & PF_FL_HASH)
		if (pf->width - 2 < pf->width)
			pf->width -= 2;
	sign = pf_check_sign(pf, nb);
	is_prec = (pf->flags & PF_FL_ZERO) && pf->prec == -1;
	if (sign && is_prec)
		pf->buff[pf->buff_len++] = sign;
	if (pf->flags & PF_FL_ZERO)
		pf_check_prefix(pf);
	if (!(pf->flags & PF_FL_MINUS))
		pf_add_symb(pf, is_prec ? '0' : ' ', res_len);
	if (sign && !is_prec)
		pf->buff[pf->buff_len++] = sign;
	if (!(pf->flags & PF_FL_ZERO))
		pf_check_prefix(pf);
	while (len++ < res_len)
		pf->buff[pf->buff_len++] = '0';
	return (res_len);
}

void			pf_handle_x(t_printf *restrict pf, intmax_t nb, char *str)
{
	size_t	len;

	len = ft_strlen(str);
	pf_check_mem(pf, pf->width + len + 1);
	len = pf_pre_x(pf, nb, len);
	pf_add_str_2_buff(pf, str, len);
	if (pf->flags & PF_FL_MINUS)
		pf_add_symb(pf, ' ', len);
	ft_strdel(&str);
}
