/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_nb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:44:39 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/29 20:43:54 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		pf_check_sign(t_printf *restrict pf, intmax_t nb, size_t *len,
																size_t *res_len)
{
	char		sign;

	if (nb < 0)
		sign = ('-');
	else if (pf->flags & PF_FL_PLUS)
		sign = ('+');
	else if (pf->flags & PF_FL_SPACE)
		sign = (' ');
	else
		return (0);
	// убрать костыль!!!
	if (!nb && !pf->prec)
	{
		if (pf->width)
			--pf->width;
		return (sign);
	}
	++(*len);
	++(*res_len);
	return (sign);
}

static void		pf_check_spec(t_printf *restrict pf, size_t *len, size_t *res_len, char spec)
{
	if ((spec == 'x' && pf->flags & PF_FL_HASH) || spec == 'p')
			ft_memcpy(pf->buff + pf->buff_len, "0x", 2);
	else
		return ;
	pf->buff_len += 2;
	(*len) += 2;
	(*res_len) += 0;
}

static size_t	pf_pre(t_printf *restrict pf, intmax_t nb, size_t len, char spec)
{
	char		sign;
	size_t		res_len;
	char		is_prec;

	if ((int)len < pf->prec || (!pf->prec && !nb))
		res_len = pf->prec;
	else
		res_len = len;
	sign = pf_check_sign(pf, nb, &len, &res_len);
	is_prec = (pf->flags & PF_FL_ZERO) && pf->prec == -1;
	pf_check_spec(pf, &len, &res_len, spec);
	if (sign && is_prec)
		pf->buff[pf->buff_len++] = sign;
	if (!(pf->flags & PF_FL_MINUS))
		pf_add_width(pf, res_len, is_prec ? '0' : ' ');
	if (sign && !is_prec)
		pf->buff[pf->buff_len++] = sign;
	while (len++ < res_len)
		pf->buff[pf->buff_len++] = '0';
	return (res_len);
}

void			pf_handle_nb(t_printf *restrict pf, intmax_t nb, char *str, char spec)
{
	size_t	len;

	len = ft_strlen(str);
	pf_check_mem(pf, pf->width + len + 1);
	len = pf_pre(pf, nb, len, spec);
	pf_add_str_2_buff(pf, str, len);
	if (pf->flags & PF_FL_MINUS)
		pf_add_width(pf, len, ' ');
	ft_strdel(&str);
}

intmax_t	pf_convert_nb(t_pf_mod_len mod, intmax_t num)
{
	if (mod == PF_ML_H)
		return ((short)num);
	else if (mod == PF_ML_HH)
		return ((char)num);
	else if (mod == PF_ML_L)
		return ((long)num);
	else if (mod == PF_ML_LL)
		return ((long long)num);
	else if (mod == PF_ML_J || mod == PF_ML_T)
		return ((intmax_t)num);
	else if (mod == PF_ML_Z)
		return ((size_t)num);
	else
		return ((int)num);
}

intmax_t	pf_convert_unb(t_pf_mod_len mod, intmax_t num)
{
	if (mod == PF_ML_H)
		return ((unsigned short)num);
	else if (mod == PF_ML_HH)
		return ((unsigned char)num);
	else if (mod == PF_ML_L)
		return ((unsigned long)num);
	else if (mod == PF_ML_LL)
		return ((unsigned long long)num);
	else if (mod == PF_ML_J || mod == PF_ML_T)
		return ((uintmax_t)num);
	else if (mod == PF_ML_Z)
		return ((size_t)num);
	else
		return ((unsigned int)num);
}
