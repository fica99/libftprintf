/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:06:45 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/27 22:57:23 by aashara-         ###   ########.fr       */
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
	char		*res;

	if (pf->flags & PF_FL_MINUS)
		pf->flags &= ~PF_FL_ZERO;
	num = va_arg(pf->argptr, intmax_t);
	if (pf->mod == PF_ML_H)
		res = ft_iltoa((short)num);
	else if (pf->mod == PF_ML_HH)
		res = ft_iltoa((char)num);
	else if (pf->mod == PF_ML_L)
		res = ft_iltoa((long)num);
	else if (pf->mod == PF_ML_LL)
		res = ft_iltoa((long long)num);
	else if (pf->mod == PF_ML_J || pf->mod == PF_ML_T)
		res = ft_iltoa((intmax_t)num);
	else if (pf->mod == PF_ML_Z)
		res = ft_iltoa((size_t)num);
	else
		res = ft_iltoa((int)num);
	pf_add_str(pf, res);
	free(res);
}
