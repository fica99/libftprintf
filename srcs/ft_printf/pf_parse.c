/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:38:24 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/25 22:55:54 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	pf_parse_flags(const char *restrict format,
									t_printf *restrict pf)
{
	char	is_valid;

	pf->flags = PF_FL_INIT;
	is_valid = TRUE;
	while (format[++(pf->i)] && is_valid)
	{
		(pf->flags) |= pf_flags_table()[(size_t)format[pf->i]];
		if (!(pf->flags))
			is_valid = FALSE;
	}
}

static void	pf_parse_width(const char *restrict format, t_printf *restrict pf)
{
	pf->width = 0;
	if (ft_isdigit(format[pf->i]))
	{
		pf->width = ft_atoi(format + pf->i);
		while (ft_isdigit(format[++pf->i]))
			;
	}
}

static void	pf_parse_precision(const char *restrict format, t_printf *restrict pf)
{
	pf->prec = 0;
	if (format[pf->i] == '.')
	{
		if (ft_isdigit(format[++(pf->i)]))
		{
			pf->prec = ft_atoi(format + pf->i);
			while (ft_isdigit(format[++pf->i]))
				;
		}
	}
}

static void	pf_parse_mod(const char *restrict format, t_printf *restrict pf)
{
	t_pf_mod_len	tmp;

	pf->mod = PF_ML_INIT;
	while (format[(pf->i)])
	{
		tmp = pf_mod_table()[(size_t)format[pf->i]];
		if (pf->mod == PF_ML_H && tmp == PF_ML_H)
			pf->mod = PF_ML_HH;
		else if (pf->mod == PF_ML_L && tmp == PF_ML_L)
			pf->mod = PF_ML_LL;
		else if (tmp)
			pf->mod = tmp;
		else
			return ;
		++(pf->i);
	}
}

void		pf_parse_string(const char *restrict format, t_printf *restrict pf)
{
	if (format[pf->i] == '%')
	{
		if (format[pf->i + 1] != '%')
		{
			pf_parse_flags(format, pf);
			pf_parse_width(format, pf);
			pf_parse_precision(format, pf);
			pf_parse_mod(format, pf);
			return ;
		}
		else
			++pf->i;
	}
	if (pf->buff_len >= pf->malloc_len)
		if (!(pf->buff = ft_realloc((void*)pf->buff, pf->malloc_len, (pf->malloc_len *= 2))))
			exit(1);
	pf->buff[(pf->buff_len)++] = format[(pf->i)++];
}
