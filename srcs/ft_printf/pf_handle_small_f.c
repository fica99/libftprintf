/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_small_f.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 16:00:28 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/29 22:46:30 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		pf_is_correct_double(char *str, short exp, long mantis)
{
	if (exp == SHRT_MAX)
	{
		if (!mantis)
			ft_strcpy(str + 1, "inf");
		else
			ft_strcpy(str + 1, "nan");
		return (FALSE);
	}
	if (!exp && !mantis)
	{
		ft_strcpy(str + 1, "0");
		return (FALSE);
	}
	return (TRUE);
}

#include "stdio.h"

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
	unsigned long		res;
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

#include "stdio.h"

static char		*pf_ft_dtoi(long double num)
{
	char			sign;
	short			exp;
	unsigned long	mantis;
	unsigned char	*bites;
	char			*str;

	if (!(str = ft_strnew(1000)))
		exit(EXIT_FAILURE);
	num = pf_swap_bytes(num);
	bites = (unsigned char*)&num;
	sign = (bites[0] & (1 << 7));
	sign ? ft_strcpy(str, "-") : ft_strcpy(str, "+");
	exp = (bites[0] << 8 | bites[1]) & SHRT_MAX;
	mantis = pf_get_mantis(&bites[2]);
	printf("%d\n", exp);
	printf("%lu\n", mantis);
	if (!pf_is_correct_double(str, exp, mantis))
		return (str);
	// if (!exp)
	// 	pf_denormilize_num(exp, mantis);
	// else
	// 	pf_normilize_num(exp, mantis);
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
