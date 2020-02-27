/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:06:45 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/27 18:32:56 by aashara-         ###   ########.fr       */
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
