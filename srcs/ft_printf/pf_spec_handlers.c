/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:06:45 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/19 00:08:00 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_spec_c(t_printf *restrict pf)
{
	int			chrcter;
	char		buff[2];
	char		*str;

	chrcter = va_arg(pf->argptr, int);
	if (pf->flags & PF_FL_BIN)
	{
		str = ft_ultoa_base(chrcter, 2, '0');
		pf_add_str(pf, str);
		ft_strdel(&str);
	}
	else
	{
		buff[0] = chrcter;
		buff[1] = 0;
		pf_add_str(pf, buff);
	}
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
	char		*str;

	if (pf->flags & PF_FL_PLUS)
		pf->flags &= ~PF_FL_SPACE;
	num = va_arg(pf->argptr, intmax_t);
	num = pf_convert_nb(pf->mod, num);
	str = ft_iltoa(num);
	pf_handle_di(pf, num, str);
}

void	pf_spec_p(t_printf *restrict pf)
{
	intmax_t	num;
	char		*str;

	pf->flags &= ~PF_FL_SPACE;
	pf->flags &= ~PF_FL_PLUS;
	if (pf->flags & PF_FL_MINUS)
		pf->flags &= ~PF_FL_ZERO;
	num = va_arg(pf->argptr, intmax_t);
	str = ft_ultoa_base(num, 16, 'a');
	pf_handle_p(pf, num, str);
}
