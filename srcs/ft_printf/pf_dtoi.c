/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:17:32 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/07 18:02:35 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long double		pf_swap_bytes(long double num)
{
	unsigned char	*bites;
	unsigned char	*res_bites;
	long double		res;
	size_t			i;

	bites = (unsigned char*)&num;
	res_bites = (unsigned char*)&res;
	i = 0;
	while (i < 10)
	{
		res_bites[i] = bites[9 - i];
		++i;
	}
	return (res);
}

static short			pf_get_exp(unsigned char *bites)
{
	short	exp;

	exp = bites[0] & DEL_SIGN;
	exp <<= 8;
	exp = (exp | bites[1]) - LONG_DOUBLE_EXP;
	return (exp);
}

static unsigned long	pf_get_mantis(unsigned char *bites)
{
	unsigned long	res;
	unsigned char	*res_bites;
	size_t			i;

	res = 0;
	res_bites = (unsigned char*)&res;
	i = 0;
	while (i < 8)
	{
		res_bites[i] = bites[i];
		++i;
	}
	return (res);
}

static char				pf_is_correct_double(char *str, short exp, long mantis)
{
	if (exp - 1 == LONG_DOUBLE_EXP)
	{
		if (mantis == INF_MANTIS)
			ft_strcpy(str, "inf");
		else if (mantis)
			ft_strcpy(str, "nan");
		return (FALSE);
	}
	return (TRUE);
}

char					*pf_dtoi(long double num)
{
	uint8_t			sign;
	short			exp;
	unsigned long	mantis;
	unsigned char	*bites;
	char			*str;

	num = pf_swap_bytes(num);
	bites = (unsigned char*)&num;
	sign = (bites[0] & (1 << 7));
	exp = pf_get_exp(bites);
	mantis = pf_get_mantis(bites + 2);
	if (!(str = (char*)malloc(LONG_DOUBLE_MALLOC_LEN)))
		exit(EXIT_FAILURE);
	sign ? ft_strcpy(str, "-") : ft_strcpy(str, "+");
	if (!pf_is_correct_double(str + 1, exp, mantis))
		return (str);
	pf_exp_mantis2str(str + 1, exp, mantis);
	return (str);
}
