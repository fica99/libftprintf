/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:16:46 by ggrimes           #+#    #+#             */
/*   Updated: 2020/08/17 14:39:00 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_len_opts	*pf_pre_di(t_printf *restrict pf, intmax_t nb, t_len_opts *len_opts)
{
	char		sign;
	char		is_prec;

	sign = pf_check_sign(pf, nb);
	is_prec = (pf->flags & PF_FL_ZERO) && pf->prec == -1;
	if (sign && is_prec)
		pf->buff[pf->buff_len++] = sign;
	if (!(pf->flags & PF_FL_MINUS))
		pf_align_to_width(pf, is_prec ? '0' : ' ', len_opts);
	if (sign && !is_prec)
		pf->buff[pf->buff_len++] = sign;
	//while (len++ < res_len)
	//	pf->buff[pf->buff_len++] = '0';
	return (len_opts);
}

void			pf_handle_di(t_printf *restrict pf, intmax_t nb, char *str)
{
	t_len_opts	*len_opts;

	len_opts = pf_init_len_opts(pf, nb, str);
	pf_check_mem(pf, pf->width + len_opts->w_len + 1);
	len_opts = pf_pre_di(pf, nb, len_opts);
	pf_add_str_2_buff(pf, str, len_opts->nstr_len);
	//if (pf->flags & PF_FL_MINUS)
	//	pf_add_symb(pf, ' ', 0);
	ft_strdel(&str);
}
