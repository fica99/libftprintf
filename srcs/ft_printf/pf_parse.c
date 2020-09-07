/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 19:38:24 by aashara-          #+#    #+#             */
/*   Updated: 2020/09/07 22:32:54 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// static void	pf_parse_flags(const char *restrict format,
// 									t_printf *restrict pf)
// {
// 	t_pf_flags	tmp;

// 	pf->flags = PF_FL_INIT;
// 	while (format[pf->i])
// 	{
// 		tmp = pf_flags_table()[(size_t)format[++(pf->i)]];
// 		if (!tmp)
// 			break ;
// 		pf->flags |= tmp;
// 	}
// }

char		pf_parse_flags(const char *restrict format,
									t_printf *restrict pf)
{
	t_pf_flags	tmp;

	pf->flags = PF_FL_INIT;
	tmp = pf_flags_table()[(size_t)format[pf->i]];
	if (!tmp)
		return (0);
	pf->flags |= tmp;
	(pf->i)++;
	return (1);
}

// static void	pf_parse_width(const char *restrict format, t_printf *restrict pf)
// {
// 	pf->width = 0;
// 	if (ft_isdigit(format[pf->i]))
// 	{
// 		pf->width = ft_atoi(format + pf->i);
// 		while (ft_isdigit(format[++pf->i]))
// 			;
// 	}
// }

char		pf_parse_width(const char *restrict format, t_printf *restrict pf)
{
	pf->width = 0;
	if (ft_isdigit(format[pf->i]))
	{
		pf->width = ft_atoi(format + pf->i);
		while (ft_isdigit(format[++pf->i]))
			;
		return (1);
	}
	return (0);
}

// static void	pf_parse_precision(const char *restrict format,
// 												t_printf *restrict pf)
// {
// 	pf->prec = -1;
// 	if (format[pf->i] == '.')
// 	{
// 		if (ft_isdigit(format[++(pf->i)]))
// 		{
// 			pf->prec = ft_atoi(format + pf->i);
// 			while (ft_isdigit(format[++pf->i]))
// 				;
// 		}
// 		else
// 			pf->prec = 0;
// 	}
// }

char		pf_parse_precision(const char *restrict format,
												t_printf *restrict pf)
{
	pf->prec = -1;
	if (format[pf->i] == '.')
	{
		if (ft_isdigit(format[++(pf->i)]))
		{
			pf->prec = ft_atoi(format + pf->i);
			while (ft_isdigit(format[++pf->i]))
				;
		}
		else
			pf->prec = 0;
		return (1);
	}
	return (0);
}

// static void	pf_parse_mod(const char *restrict format, t_printf *restrict pf)
// {
// 	t_pf_mod_len	tmp;

// 	pf->mod = PF_ML_INIT;
// 	while (format[(pf->i)])
// 	{
// 		tmp = pf_mod_table()[(size_t)format[pf->i]];
// 		if (pf->mod == PF_ML_H && tmp == PF_ML_H)
// 			pf->mod = PF_ML_HH;
// 		else if (pf->mod == PF_ML_L && tmp == PF_ML_L)
// 			pf->mod = PF_ML_LL;
// 		else if (tmp)
// 			pf->mod = tmp;
// 		else
// 			return ;
// 		++(pf->i);
// 	}
// }

char		pf_parse_mod(const char *restrict format, t_printf *restrict pf)
{
	t_pf_mod_len	tmp;

	pf->mod = PF_ML_INIT;
	tmp = pf_mod_table()[(size_t)format[pf->i]];
	if (!tmp)
		return (0);
	if (pf->mod == PF_ML_H && tmp == PF_ML_H)
		pf->mod = PF_ML_HH;
	else if (pf->mod == PF_ML_L && tmp == PF_ML_L)
		pf->mod = PF_ML_LL;
	else if (tmp)
		pf->mod = tmp;
	(pf->i)++;
	return (1);
}

void		pf_parse_string(const char *restrict format, t_printf *restrict pf)
{
	void	(*f)(t_printf *pf);

	if (format[pf->i] == '%')
	{
		(pf->i)++;
		while (1)
		{
			if (pf_parse_params_str(format, pf))
				continue ;
			if (!format[pf->i])
				return ;
			if ((f = pf_spec_table(format[pf->i])))
			{
				(pf->i)++;
				f(pf);
			}
			return ;
		}
	}
	else if (format[pf->i] == '{')
		if (pf_parse_color(format, pf))
			return ;
	pf_check_mem(pf, 1);
	pf->buff[(pf->buff_len)++] = format[(pf->i)++];
}
