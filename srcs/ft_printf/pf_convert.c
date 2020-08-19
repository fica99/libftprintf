/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 20:18:04 by ggrimes           #+#    #+#             */
/*   Updated: 2020/08/19 14:53:43 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

intmax_t	pf_convert_nb(t_pf_mod_len mod, intmax_t num)
{
	if (mod == PF_ML_INIT)
		return ((int)num);
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

char	*pf_get_bits(size_t size, void *ptr)
{
	unsigned char	*b;
	char			*str;
	int				i;
	int				j;

	if (!size || !ptr)
		return (NULL);
	if (!(str = ft_strnew(size * 8)))
		exit(EXIT_FAILURE);
	b = (unsigned char*)ptr;
	i = size;
	while (--i >= 0)
	{
		j = 8;
		while (--j >= 0)
			*(str++) = ((b[i] >> j) & 1)? '1' : '0';
	}
	return (str - size * 8);
}
