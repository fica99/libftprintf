/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_exp_mantis2str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 13:55:20 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/04 21:06:00 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_double_get_num(short exp, t_list **before_coma,
														t_list **after_coma)
{
	if (exp >= 0)
	{
		ft_lstadd()
	}
	else
	{

	}
}

void				pf_exp_mantis_2str(char *str, short exp, unsigned long mantis)
{
	int8_t			i;
	int8_t			j;
	t_list			*before_coma;
	t_list			*after_coma;
	unsigned char	*num;

	i = -1;
	num = (unsigned char*)&mantis;
	ft_bzero((void*)before_coma, sizeof(t_list));
	ft_bzero((void*)after_coma, sizeof(t_list));
	while (++i < 8)
	{
		j = 8;
		while (--j >= 0)
		{
			if (num[i] & (1 << j))
				pf_double_get_num(exp, &before_coma, &after_coma);
			--exp;
		}
	}
}
