/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoa_round.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:55:39 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/12 18:15:39 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_dtoa_round_add_zeros(char **str, size_t n)
{
	char	*to_add;
	char	*tmp;

	if (!n)
		return ;
	if (!(to_add = ft_strnew(n)))
		exit(EXIT_FAILURE);
	ft_memset((void*)to_add, '0', n);
	tmp = *str;
	if (!(*str = ft_strjoin(tmp, to_add)))
		exit(EXIT_FAILURE);
	ft_strdel(&tmp);
	ft_strdel(&to_add);
}

static void			pf_dtoa_round_carry(char *str, size_t size)
{
	while (--size)
	{
		if (str[size] - 48 > 9)
		{
			str[size - 1] += (str[size] - 48) / 10;
			str[size] = (str[size] - 48) % 10 + 48;
		}
	}
}

static void			pf_dtoa_round_add(char **str, size_t i, size_t prec)
{
	size_t	size;

	if (!prec)
		(*str)[i - 2] += 1;
	else
		(*str)[i + prec - 1] += 1;
	pf_dtoa_round_carry(*str + i, prec);
	pf_dtoa_round_carry(*str, i - 1);
	size = i + prec;
	pf_dig_overflow(str, 0, &size, TRUE);
}

static void			pf_dtoa_round_cut(char **str, size_t i, size_t prec)
{
	char	*num;
	size_t	j;

	num = *str;
	if (num[i + prec] > '5')
		pf_dtoa_round_add(str, i, prec);
	else if (num[i + prec] == '5')
	{
		j = i + prec;
		while (num[++j])
		{
			if (num[j] > '0')
			{
				pf_dtoa_round_add(str, i, prec);
				break;
			}
		}
	}
	if (!prec)
		num[i - 1] = '\0';
	else
		num[i + prec] = '\0';
}

size_t				pf_dtoa_round(char **str, size_t prec)
{
	char	*num;
	size_t	i;
	size_t	j;

	num = *str;
	i = 0;
	while (num[i] != '.')
		++i;
	j = 0;
	++i;
	while (num[i + j] && j < prec)
		++j;
	if (!num[i + j])
		pf_dtoa_round_add_zeros(str, prec - j);
	else
	{
		pf_dtoa_round_cut(str, i, prec);
		if (!prec)
			--i;
	}
	return (i + prec);
}
