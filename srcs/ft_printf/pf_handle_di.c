/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_di.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:16:46 by ggrimes           #+#    #+#             */
/*   Updated: 2020/08/17 16:08:33 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	*pf_pre_di(t_printf *restrict pf, t_len_opts *len_opts)
{
	char		is_prec;

	is_prec = (pf->flags & PF_FL_ZERO) && pf->prec == -1;
	if (len_opts->sign && is_prec)
		pf->buff[pf->buff_len++] = len_opts->sign;
	if (!(pf->flags & PF_FL_MINUS))
		pf_align_to_width(pf, is_prec ? '0' : ' ', len_opts);
	if (len_opts->sign && !is_prec)
		pf->buff[pf->buff_len++] = len_opts->sign;
	pf_align_to_accuracy(pf, '0', len_opts);
	return (len_opts);
}

void	pf_handle_di(t_printf *restrict pf, intmax_t nb, char *str)
{
	t_len_opts	*len_opts;

	len_opts = pf_init_len_opts(pf, nb, str);
	pf_check_mem(pf, pf->width + len_opts->w_len + 1);
	pf_pre_di(pf, len_opts);
	pf_add_str_2_buff(pf, str, len_opts->nstr_len);
	if (pf->flags & PF_FL_MINUS)
		pf_align_to_width(pf, ' ', len_opts);
	ft_strdel(&str);
}
