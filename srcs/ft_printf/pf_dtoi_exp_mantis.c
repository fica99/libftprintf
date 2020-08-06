/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoi_exp_mantis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 19:25:20 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/06 22:10:31 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			pf_add_elem2list(char to_start, t_list **head, t_list *el)
{
	t_list	*tmp;

	if (to_start)
		ft_lstadd(head, el);
	else
	{
		tmp = *head;
		if (!tmp)
			*head = el;
		else
		{
			while (tmp->next)
				tmp = tmp->next;
			tmp->next = el;
		}
	}
}

static void			pf_handle_active_bite(short exp, t_list **before_coma,
														t_list **after_coma)
{
	char	*content;
	t_list	*el;

	content = NULL;
	if (exp >= 0)
	{
		if (!*before_coma)// add check what is better division or pow
			content = pf_pow(2, exp);
		else// find bug with adding element to list
			content = pf_div_pow((*before_coma)->content,
							*pf_get_last_exp(), exp, 2);
		el = ft_lstnew(content, log10(2) * exp + 1);
		pf_add_elem2list(TRUE, before_coma, el);
	}
	else
	{
		//handle mul
		content = pf_pow(5, ft_abs(exp));
		el = ft_lstnew(content, log10(5) * ft_abs(exp) + 1);
		pf_add_elem2list(FALSE, after_coma, el);
	}
	*pf_get_last_exp() = exp;
}

static char			*pf_sum_pows(t_list *head)
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

static void			pf_sum_lists2str(char *str, t_list *before_coma,
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
	pf_sum_lists2str(str, before_coma, after_coma);
	ft_lstdel(&before_coma, NULL);
	ft_lstdel(&after_coma, NULL);
}
