/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_small_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:00:28 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/05 19:56:58 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		pf_is_correct_double(char *str, short exp, long mantis)
{
	if (exp - 1 == LONG_DOUBLE_EXP)
	{
		if (mantis == INF_MANTIS)
			ft_strcpy(str + 1, "inf");
		else if (mantis)
			ft_strcpy(str + 1, "nan");
		return (FALSE);
	}
	return (TRUE);
}

static long double	pf_swap_bytes(long double num)
{
	unsigned char	*bites;
	unsigned char	*res_bites;
	long double		res;
	size_t			i;

	bites = (unsigned char*)&num;
	res_bites = (unsigned char*)&res;
	i = 0;
	while (i < 10) {
		res_bites[i] = bites[9 - i];
		++i;
	}
	return (res);
}

static unsigned long		pf_get_mantis(unsigned char *bites)
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

static char		*pf_ft_dtoi(long double num)
{
	uint8_t			sign;
	short			exp;
	unsigned long	mantis;
	unsigned char	*bites;
	char			*str;

	num = pf_swap_bytes(num);
	bites = (unsigned char*)&num;
	sign = (bites[0] & (1 << 7));
	exp = bites[0] & DEL_SIGN;
	exp <<= 8;
	exp = (exp | bites[1]) - LONG_DOUBLE_EXP;
	mantis = pf_get_mantis(bites + 2);
	if (!(str = ft_strnew(DOUBLE_MALLOC_LEN))))
		exit(EXIT_FAILURE);
	sign ? ft_strcpy(str, "-") : ft_strcpy(str, "+");
	if (!pf_is_correct_double(str, exp, mantis))
		return (str);
	pf_exp_mantis2str(str + 1, exp, mantis);
	return (str);
}

void			pf_spec_small_f(t_printf *restrict pf)
{
	long double	num;
	char		*str;
	size_t		len;

	// if (pf->prec == -1)
	// 	pf->prec = 6;
	if (pf->flags & PF_ML_L)
		num = va_arg(pf->argptr, long double);
	else
		num = va_arg(pf->argptr, double);
	str = pf_ft_dtoi(num);
	len = ft_strlen(str);
	pf_check_mem(pf, len);
	pf_add_str_2_buff(pf, str, len);
	ft_strdel(&str);
}
