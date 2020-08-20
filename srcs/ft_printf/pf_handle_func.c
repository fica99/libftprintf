/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:30:05 by olegmulko         #+#    #+#             */
/*   Updated: 2020/08/20 10:21:02 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_align_to_width(t_printf *restrict pf, char c, t_len_opts *len_opts)
{
	size_t	i;

	i = len_opts->ac_len;
	while (i < len_opts->w_len)
	{
		pf->buff[(pf->buff_len)++] = c;
		i++;
	}
}

void	pf_align_to_accuracy(t_printf *restrict pf, char c,
	t_len_opts *len_opts)
{
	size_t	i;

	i = len_opts->num_len;
	while (i < len_opts->ac_len)
	{
		pf->buff[(pf->buff_len)++] = c;
		i++;
	}
}

char	*pf_get_str_null(t_printf *restrict pf)
{
	size_t	ac_len;

	if (pf->width > 0 && pf->prec < 1)
		ac_len = pf->width;
	else if (pf->prec > 0)
		ac_len = pf->prec;
	else
		ac_len = 6;
	if (ac_len < 6)
		return ("");
	return ("(null)");
}
