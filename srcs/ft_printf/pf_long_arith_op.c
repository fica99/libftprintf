/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_long_arith_op.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 18:40:09 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/05 20:03:59 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_carry(char *content, int size)
{
	while (--size)
	{
		if (content[size] > 9)
		{
			content[size - 1] += content[size] / 10;
			content[size] %= 10;
		}
	}
}

static void		pf_exp(char *content, int size, short pow)
{
	int tmp;

	tmp = size;
	while (--tmp >= 0)
		content[tmp] *= pow;
	pf_carry(content, size);
}

char			*pf_ft_pow(short pow, short exp)
{
	char	*content;
	int		size;

	size = log10(pow) * exp + 1;
	if (!(content = ft_strnew(size)))
		exit(EXIT_FAILURE);
	content[size - 1] = 1;
	while (exp--)
		pf_exp(content, size, pow);
	return (content);
}

char			*pf_pows2str(t_list *list)
{

}
