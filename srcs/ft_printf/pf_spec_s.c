/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_spec_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 22:31:50 by ggrimes           #+#    #+#             */
/*   Updated: 2020/02/26 23:31:59 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void     pf_add_str(t_printf *restrict pf, const char *str, size_t len)
{
    size_t      i;

    i = 0;
    while (i < len)
        pf->buff[(pf->buff_len)++] = str[i++];
}

static void     pf_str(t_printf *restrict pf, const char *str)
{
    size_t      len;
    size_t      count_sp;

    len = ft_strlen(str);
    len = (pf->prec < len) ? pf->prec : len;
    count_sp = (pf->width - len > pf->width) ? 0 : pf->width - len;
	pf_check_mem(pf, ((len >= pf->width) ? len : pf->width) + 1);
	if (pf->flags & PF_FL_MINUS)
	{
        pf_add_str(pf, str, len);
        pf_add_spaces(pf, count_sp);
	}
	else
	{
        pf_add_spaces(pf, count_sp);
		pf_add_str(pf, str, len);
	}
}

// move to a file with common functions!!!
void            pf_add_spaces(t_printf *restrict pf, size_t n)
{
    size_t      len;

    if (n == 0)
        return ;
    len = pf->buff_len + n;
    while (pf->buff_len < len)
        pf->buff[(pf->buff_len)++] = ' ';
}

void	        pf_spec_s(t_printf *restrict pf)
{
	char		*str;
	
	str = va_arg(pf->argptr, char*);
    pf_str(pf, str);
}