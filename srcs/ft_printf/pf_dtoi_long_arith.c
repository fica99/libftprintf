/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoi_long_arith.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:29:37 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/07 15:15:39 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			pf_carry(char *res, int size)
{
	char	to_add;

	to_add = 0;
	while (--size)
	{
		if (res[size] > 9)
		{
			res[size - 1] += res[size] / 10;
			res[size] %= 10;
		}
	}
	if (res[0] > 9)
	{
		to_add += res[0] / 10;
		res[0] %= 10;
	}
	return (to_add);
}

static void		pf_exp(char *res, int size, short pow)
{
	int tmp;

	tmp = size;
	while (--tmp >= 0)
		res[tmp] *= pow;
	pf_carry(res, size);
}

char			*pf_pow(short pow, short exp)
{
	char	*res;
	int		size;

	size = log10(pow) * exp + 1;
	if (!(res = ft_strnew(size)))
		exit(EXIT_FAILURE);
	res[size - 1] = 1;
	while (exp--)
		pf_exp(res, size, pow);
	return (res);
}

char			*pf_update_nums2str(char *str, char *num, size_t num_len)
{
	size_t	i;

	if (!num || !num_len)
	{
		str[0] = '0';
		return (str + 1);
	}
	i = 0;
	while (i < num_len)
	{
		str[i] = num[i] + 48;
		++i;
	}
	return (str + i);
}

char			*pf_div_pow(char *num, short prev_exp, short exp, short pow)
{
	size_t	len;
	size_t	j;
	int		tmp;
	char	*res;
	short	div;

	div = (short)ft_pow(pow, ft_abs(prev_exp - exp));
	if (!(res = ft_strnew(log10(pow) * exp + 1)))
		exit(EXIT_FAILURE);
	tmp = *num;
	len = log10(pow) * prev_exp + 1;
	while (tmp < div && len--)
		tmp = tmp * 10 + *(++num);
	j = 0;
	while (len--)
	{
		res[j++] = tmp / div;
		tmp = tmp % div;
		tmp = tmp * 10 + *(++num);
	}
	return (res);
}
