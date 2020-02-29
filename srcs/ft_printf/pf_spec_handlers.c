/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:06:45 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/29 17:42:56 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_spec_c(t_printf *restrict pf)
{
	int			chrcter;
	char		buff[2];

	chrcter = va_arg(pf->argptr, int);
	buff[0] = chrcter;
	buff[1] = 0;
	pf_add_str(pf, buff);
}

void	pf_spec_s(t_printf *restrict pf)
{
	char		*str;

	str = va_arg(pf->argptr, char*);
	pf_add_str(pf, str);
}

void	pf_spec_percent(t_printf *restrict pf)
{
	pf_add_str(pf, "%");
}

void	pf_spec_int(t_printf *restrict pf)
{
	intmax_t	num;

	if (pf->flags & PF_FL_PLUS)
		pf->flags &= ~PF_FL_SPACE;
	num = va_arg(pf->argptr, intmax_t);
	if (pf->mod == PF_ML_H)
		pf_handle_int(pf, (short)num);
	else if (pf->mod == PF_ML_HH)
		pf_handle_int(pf, (char)num);
	else if (pf->mod == PF_ML_L)
		pf_handle_int(pf, (long)num);
	else if (pf->mod == PF_ML_LL)
		pf_handle_int(pf, (long long)num);
	else if (pf->mod == PF_ML_J || pf->mod == PF_ML_T)
		pf_handle_int(pf, (intmax_t)num);
	else if (pf->mod == PF_ML_Z)
		pf_handle_int(pf, (size_t)num);
	else
		pf_handle_int(pf, (int)num);
}

void	pf_spec_pointer(t_printf *restrict pf)
{
	intmax_t	num;
	char		*str;

	pf->flags &= ~PF_FL_SPACE;
	pf->flags &= ~PF_FL_PLUS;
	if (pf->flags & PF_FL_MINUS)
		pf->flags &= ~PF_FL_ZERO;
	num = va_arg(pf->argptr, intmax_t);
	str = ft_ultoa_base(num, 16, 'a');
	ft_strdel(&str);
}
