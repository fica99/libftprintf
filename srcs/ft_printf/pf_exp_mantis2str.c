/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_exp_mantis2str.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/01 13:55:20 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/05 20:01:14 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_calc_pows2str(char *str, t_list *before_coma,
															t_list *after_coma)
{
	int	len;

	ft_strcat(str, pf_pows2str(before_coma));
	len = ft_strlen(str);
	ft_strcat(str + len, ".");
	ft_strcat(str + len + 1, pf_pows2str(after_coma));
}

static void			pf_double_get_num(short exp, t_list **before_coma,
														t_list **after_coma)
{
	char	*content;
	t_list	*el;

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
		ft_lstadd(after_coma, el);
	}
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
				pf_double_get_num(exp, &before_coma, &after_coma);
			--exp;
		}
	}
	pf_calc_pows2str(str, before_coma, after_coma);
	ft_lstdel(&before_coma, NULL);
	ft_lstdel(&after_coma, NULL);
}
