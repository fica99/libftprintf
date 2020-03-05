/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_handlers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:50:16 by aashara-          #+#    #+#             */
/*   Updated: 2020/03/05 21:46:48 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_spec_x(t_printf *restrict pf, char is_big)
{
	intmax_t	num;
	char		*str;

	pf->flags &= ~PF_FL_SPACE;
	pf->flags &= ~PF_FL_PLUS;
	if (pf->flags & PF_FL_MINUS)
		pf->flags &= ~PF_FL_ZERO;
	num = va_arg(pf->argptr, intmax_t);
	num = pf_convert_unb(pf->mod, num);
	str = ft_ultoa_base(num, 16, (is_big) ? 'A' : 'a');
	pf_handle_x(pf, num, str, is_big);
}

void			pf_spec_big_x(t_printf *restrict pf)
{
	pf_spec_x(pf, 1);
}

void			pf_spec_small_x(t_printf *restrict pf)
{
	pf_spec_x(pf, 0);
}
