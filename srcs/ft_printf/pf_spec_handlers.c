/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_handlers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:06:45 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/26 22:30:31 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_spec_c(t_printf *restrict pf)
{
	int			chrcter;

	chrcter = va_arg(pf->argptr, int);
	pf_add_char(pf, chrcter);
}

void	pf_spec_s(t_printf *restrict pf)
{
	char		*str;
	
	str = va_arg(pf->argptr, char*);
}
