/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_small_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:00:28 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/07 16:33:35 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			pf_spec_small_f(t_printf *restrict pf)
{
	long double	num;
	char		*str_num;
	size_t		nb_len;

	// if (pf->prec == -1)
	// 	pf->prec = 6;
	if (pf->flags & PF_ML_L)
		num = va_arg(pf->argptr, long double);
	else
		num = va_arg(pf->argptr, double);
	str_num = pf_dtoi(num);
	nb_len = ft_strlen(str_num);
	pf_check_mem(pf, nb_len);
	pf_add_str_2_buff(pf, str_num, nb_len);
	ft_strdel(&str_num);
}
