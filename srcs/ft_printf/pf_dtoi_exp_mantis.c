/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoi_exp_mantis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:25:20 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/06 19:59:26 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_handle_active_bite(short exp, t_list **before_coma,
														t_list **after_coma)
{
	char	*content;
	t_list	*el;
	t_list	*tmp;

	content = NULL;
	if (exp >= 0)
	{
		// if (!*before_coma)
			content = pf_ft_pow(2, exp);
		el = ft_lstnew(content, log10(2) * exp + 1);
		ft_lstadd(before_coma, el);
	}
	else
	{
		// if (!*after_coma)
			content = pf_ft_pow(5, ft_abs(exp));
		el = ft_lstnew(content, log10(5) * ft_abs(exp) + 1);
		tmp = *after_coma;
		if (!tmp)
			*after_coma = el;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = el;
		}
	}
}


static char			*pf_update_nums2str(char *str, char *num)
{
	size_t	i;

	if (!num)
	{
		str[0] = '0';
		return (str + 1);
	}
	i = 0;
	while (num[i])
	{
		str[i] = num[i] + 48;
		++i;
	}
	return (str + i);
}

static void			pf_sum_pows2str(char *str, t_list *before_coma,
															t_list *after_coma)
{

	char	*num;

	num = pf_sum_pows(before_coma);
	str = pf_update_nums2str(str, num);
	*(str++) = '.';
	num = pf_sum_pows(after_coma);
	str = pf_update_nums2str(str, num);
	*str = '\0';
}

void				pf_exp_mantis2str(char *str, short exp, unsigned long mantis)
{
	int8_t			i;
	int8_t			j;
	t_list			*before_coma;
	t_list			*after_coma;
	unsigned char	*num;

	i = -1;
	num = (unsigned char*)&mantis;
	before_coma = NULL;
	after_coma = NULL;
	while (++i < 8)
	{
		j = 8;
		while (--j >= 0)
		{
			if (num[i] & (1 << j))
				pf_handle_active_bite(exp, &before_coma, &after_coma);
			--exp;
		}
	}
	pf_sum_pows2str(str, before_coma, after_coma);
	ft_lstdel(&before_coma, NULL);
	ft_lstdel(&after_coma, NULL);
}
