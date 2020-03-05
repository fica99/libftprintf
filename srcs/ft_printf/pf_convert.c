/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggrimes <ggrimes@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:18:04 by ggrimes           #+#    #+#             */
/*   Updated: 2020/03/05 21:46:40 by ggrimes          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	pf_convert_nb(t_pf_mod_len mod, intmax_t num)
{
	if (mod == PF_ML_INIT)
		return ((unsigned int) num);
	else if (mod == PF_ML_H)
		return ((short)num);
	else if (mod == PF_ML_HH)
		return ((char)num);
	else if (mod == PF_ML_L)
		return ((long)num);
	else if (mod == PF_ML_LL)
		return ((long long)num);
	else if (mod == PF_ML_J || mod == PF_ML_T)
		return ((intmax_t)num);
	else if (mod == PF_ML_Z)
		return ((size_t)num);
	else
		return ((int)num);
}

intmax_t	pf_convert_unb(t_pf_mod_len mod, intmax_t num)
{
	if (mod == PF_ML_H)
		return ((unsigned short)num);
	else if (mod == PF_ML_HH)
		return ((unsigned char)num);
	else if (mod == PF_ML_L)
		return ((unsigned long)num);
	else if (mod == PF_ML_LL)
		return ((unsigned long long)num);
	else if (mod == PF_ML_J || mod == PF_ML_T)
		return ((uintmax_t)num);
	else if (mod == PF_ML_Z)
		return ((size_t)num);
	else
		return ((unsigned int)num);
}
