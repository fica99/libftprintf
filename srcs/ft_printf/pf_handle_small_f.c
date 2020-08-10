/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_small_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:00:28 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/10 16:51:09 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_double_invalid_str_nan(t_printf *pf, char *str_num)
{
	pf_check_mem(pf, 3 + pf->width);
	if (!(pf->flags & PF_FL_MINUS))
		pf_add_symb(pf, ' ', 3);
	pf_add_str_2_buff(pf, ++str_num, 3);
}

static void		pf_double_invalid_str_inf(t_printf *pf, char *str_num)
{
	size_t	len;

	pf_check_mem(pf, 4 + pf->width);
	len = 3;
	if (str_num[0] == '-')
		++len;
	else
	{
		if (pf->flags & PF_FL_PLUS)
			++len;
		else
			++str_num;
	}
	if (pf->flags & PF_FL_SPACE && str_num[0] == '+')
	{
		pf_add_str_2_buff(pf, " ", 1);
		if (pf->width)
			--pf->width;
	}
	if (!(pf->flags & PF_FL_MINUS))
		pf_add_symb(pf, ' ', len);
	pf_add_str_2_buff(pf, str_num, len);
}

void			pf_spec_small_f(t_printf *restrict pf)
{
	long double	num;
	char		*str_num;
	// size_t		nb_len;

	if (pf->prec == -1)
		pf->prec = 6;
	if (pf->flags & PF_FL_PLUS)
		pf->flags &= ~PF_FL_SPACE;
	if (pf->mod & PF_ML_BL)
		num = va_arg(pf->argptr, long double);
	else
		num = va_arg(pf->argptr, double);
	str_num = pf_dtoi(num);
	if (!ft_isdigit((str_num[1])))
		str_num[1] == 'n' ? pf_double_invalid_str_nan(pf, str_num) :
							pf_double_invalid_str_inf(pf, str_num);
	else
	{

	}
	ft_strdel(&str_num);
}
