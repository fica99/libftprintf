/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:06:45 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/27 17:47:01 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_spec_c(t_printf *restrict pf)
{
	int			chrcter;

	chrcter = va_arg(pf->argptr, int);
	pf_add_char(pf, chrcter);
}

// void	pf_spec_s(t_printf *restrict pf)
// {
// 	char		*str;
// 	size_t		len;
// 	size_t		count_sp;

// 	str = va_arg(pf->argptr, char*);
// 	len = ft_strlen(str);
// 	len = (pf->prec < len) ? pf->prec : len;
// 	count_sp = (pf->width - len > pf->width) ? 0 : pf->width - len;
// 	pf_check_mem(pf, ((len >= pf->width) ? len : pf->width) + 1);
// 	if (pf->flags & PF_FL_MINUS)
// 	{
// 		pf_add_str(pf, str, len);
// 		pf_add_spaces(pf, count_sp);
// 	}
// 	else
// 	{
// 		pf_add_spaces(pf, count_sp);
// 		pf_add_str(pf, str, len);
// 	}
// }

void	pf_spec_percent(t_printf *restrict pf)
{
	pf_add_char(pf, '%');
}
