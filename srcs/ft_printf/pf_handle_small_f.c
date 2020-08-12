/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_small_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:00:28 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/13 01:32:10 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_double_invalid_str_nan(t_printf *pf, char *str_num)
{
	pf_check_mem(pf, 3 + pf->width);
	if (!(pf->flags & PF_FL_MINUS))
		pf_add_symb(pf, ' ', 3);
	pf_add_str_2_buff(pf, ++str_num, 3);
}

static void	pf_double_handle_flags(t_printf *pf, char *str_num, size_t len)
{
	char	sign;

	pf_check_mem(pf, len + pf->width + 3);
	sign = pf_check_sign(pf, str_num[0] == '+' ? 1 : -1);
	if (!sign)
		--len;
	if (sign && (pf->flags & PF_FL_ZERO))
		pf->buff[pf->buff_len++] = sign;
	if (!(pf->flags & PF_FL_MINUS))
		pf_add_symb(pf, (pf->flags & PF_FL_ZERO) ? '0' : ' ', len);
	if (sign && !(pf->flags & PF_FL_ZERO))
		pf->buff[pf->buff_len++] = sign;
	pf_add_str_2_buff(pf, ++str_num, len);
	if ((pf->flags & PF_FL_HASH) && !pf->prec)
	{
		pf_add_str_2_buff(pf, ".", ++len);
	}
	if (pf->flags & PF_FL_MINUS)
		pf_add_symb(pf, ' ', len);
}

void		pf_spec_small_f(t_printf *restrict pf)
{
	long double	num;
	char		*str_num;
	size_t		len;

	if (pf->prec == -1)
		pf->prec = 6;
	if (pf->flags & PF_FL_PLUS)
		pf->flags &= ~PF_FL_SPACE;
	if (pf->mod & PF_ML_BL)
		num = va_arg(pf->argptr, long double);
	else
		num = va_arg(pf->argptr, double);
	str_num = NULL;
	len = pf_dtoa(&str_num, num, pf->prec);
	if (str_num[1] == 'n')
		pf_double_invalid_str_nan(pf, str_num);
	else
		pf_double_handle_flags(pf, str_num, len);
	ft_strdel(&str_num);
}
