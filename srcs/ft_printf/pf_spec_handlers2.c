/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_handlers2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/29 18:50:16 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/29 20:38:33 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_spec_x(t_printf *restrict pf)
{
	intmax_t	num;
	char		*str;

	pf->flags &= ~PF_FL_SPACE;
	pf->flags &= ~PF_FL_PLUS;
	if (pf->flags & PF_FL_MINUS)
		pf->flags &= ~PF_FL_ZERO;
	num = va_arg(pf->argptr, intmax_t);
	num = pf_convert_unb(pf->mod, num);
	str = ft_ultoa_base(num, 16, 'a');
	pf_handle_nb(pf, num, str, 'x');
}
