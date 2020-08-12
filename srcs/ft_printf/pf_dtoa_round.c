/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoa_round.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/12 13:55:39 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/12 19:13:10 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_dtoa_round_add(char **str, size_t i, size_t prec)
{
	size_t	size;

	if (!prec)
		(*str)[i - 2] += 1;
	else
		(*str)[i + prec - 1] += 1;
	pf_carry(*str + i, prec, TRUE);
	pf_carry(*str, i - 1, TRUE);
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
				break ;
			}
		}
	}
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
		ft_memset(*str + i + j, '0', prec - j);
	else
		pf_dtoa_round_cut(str, i, prec);
	if (!prec)
		(*str)[--i] = '\0';
	else
		(*str)[i + prec] = '\0';
	return (i + prec);
}
