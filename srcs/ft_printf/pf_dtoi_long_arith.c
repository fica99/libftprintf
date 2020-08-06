/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoi_long_arith.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:29:37 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/06 19:41:41 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_carry(char *res, int size)
{
	while (--size)
	{
		if (res[size] > 9)
		{
			res[size - 1] += res[size] / 10;
			res[size] %= 10;
		}
	}
}

static void		pf_exp(char *res, int size, short pow)
{
	int tmp;

	tmp = size;
	while (--tmp >= 0)
		res[tmp] *= pow;
	pf_carry(res, size);
}

char			*pf_ft_pow(short pow, short exp)
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

char			*pf_sum_pows(t_list *head)
{
	t_list	*tmp;
	int		head_size;
	int		tmp_size;
	char	*content;
	char	*tmp_content;

	if (!head)
		return (NULL);
	tmp = head->next;
	content = head->content;
	while (tmp)
	{
		head_size = head->content_size;
		tmp_size = tmp->content_size;
		tmp_content = tmp->content;
		while (--tmp_size >= 0)
			content[--head_size] += tmp_content[tmp_size];
		pf_carry(head->content, head->content_size);
		tmp = tmp->next;
	}
	return (content);
}
