/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_double_exp_mantis2str.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 13:55:20 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/02 11:59:11 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_double_add_nums2str(char *str,
				unsigned long before_coma, unsigned long long after_coma)
{
	char	*tmp;

	if (!(tmp = ft_iltoa(before_coma)))
		exit(EXIT_FAILURE);
	ft_strcpy(str, tmp);
	ft_strdel(&tmp);
	ft_strcat(str, ".");
	if (!(tmp = ft_iltoa(after_coma)))
		exit(EXIT_FAILURE);
	ft_strcat(str, tmp);
	ft_strdel(&tmp);
}

#include "stdio.h"

static void			pf_double_get_num(short exp, unsigned long *before_coma, long double *after_coma)
{
	if (exp >= 0)
		(*before_coma) += ft_pow(2, exp);
	else {
		(*after_coma) += ft_pow(2, exp);
	}
	printf("Exp - %d, After coma - %Lf\n", exp, *after_coma);
}

void				pf_double_exp_mantis_2str(char *str, short exp,
													unsigned long mantis)
{
	int8_t			i;
	int8_t			j;
	unsigned long	before_coma;
	long double		after_coma;
	unsigned char	*num;

	i = -1;
	num = (unsigned char*)&mantis;
	before_coma = 0;
	after_coma = 0;
	printf("Exp - %d\nMantis - %lu\n", exp, mantis);
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
	pf_double_add_nums2str(str, before_coma, (unsigned long long)after_coma);
}
