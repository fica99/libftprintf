/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse_params_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/07 22:05:03 by ggrimes           #+#    #+#             */
/*   Updated: 2020/09/07 22:34:15 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	pf_parse_params_str(const char *restrict format,
									t_printf *restrict pf)
{
	if (pf_parse_flags(format, pf))
		return (1);
	if (pf_parse_width(format, pf))
		return (1);
	if (pf_parse_precision(format, pf))
		return (1);
	if (pf_parse_mod(format, pf))
		return (1);
	if (pf_parse_undefined(format, pf))
		return (1);
	return (0);
}
