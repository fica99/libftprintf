/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoi_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:22:24 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/07 18:21:18 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list		*pf_get_last(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void		pf_add_elem2list(char to_start, t_list **head, t_list *el)
{
	t_list	*last;

	if (to_start)
		ft_lstadd(head, el);
	else
	{
		last = pf_get_last(*head);
		if (!last)
			*head = el;
		else
			last->next = el;
	}
}

void		pf_first_dig_overflow(t_list *el)
{
	unsigned char	*num;
	unsigned char	to_add;

	if (!el)
		return ;
	num = el->content;
	to_add = 0;
	if (num[0] > 9)
	{
		to_add += num[0] / 10;
		num[0] %= 10;
		if (!(num = ft_memalloc(el->content_size + 1)))
			exit(EXIT_FAILURE);
		ft_memcpy(num + 1, el->content, el->content_size);
		num[0] = to_add;
		ft_memdel(&el->content);
		el->content = num;
		++el->content_size;
	}
}

char		*pf_update_nums2str(char *str, t_list *el)
{
	size_t	i;
	char	*num;

	if (!el)
	{
		str[0] = '0';
		return (str + 1);
	}
	i = 0;
	num = el->content;
	while (i < el->content_size)
	{
		str[i] = num[i] + 48;
		++i;
	}
	return (str + i);
}
