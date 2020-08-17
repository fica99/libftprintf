/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_len_opts.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:21:30 by olegmulko         #+#    #+#             */
/*   Updated: 2020/08/17 14:21:34 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_len_opts	*pf_init_len_opts(t_printf *restrict pf, intmax_t nb, char *str)
{
	t_len_opts	*len_opts;

	if (!(len_opts = (t_len_opts*)malloc(sizeof(t_len_opts))))
		exit(1);
	len_opts->num_len = pf_get_num_len(pf, nb, str);
	len_opts->w_len = pf_get_w_len(pf, len_opts->num_len);
	len_opts->ac_len = pf_get_ac_len(pf, nb, len_opts->num_len);
	len_opts->nstr_len = ft_strlen(str);
	return (len_opts);
}

size_t	pf_get_num_len(t_printf *restrict pf, intmax_t nb, char *str)
{
	size_t	num_len;
	char	sign;

	num_len = ft_strlen(str);
	sign = pf_check_sign(pf, nb);
	if (sign)
		num_len++;
	return (num_len);
}

size_t	pf_get_w_len(t_printf *restrict pf, size_t num_len)
{
	if (pf->width > num_len)
		return (pf->width);
	return (num_len);
}

size_t	pf_get_ac_len(t_printf *restrict pf, intmax_t nb, size_t num_len)
{
	if ((int)num_len < pf->prec || (!pf->prec && !nb))
		return ((size_t)pf->prec);
	return (num_len);
}
