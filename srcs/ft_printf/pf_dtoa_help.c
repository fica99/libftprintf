/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoa_help.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:22:24 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/12 18:02:37 by aashara-         ###   ########.fr       */
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

void		pf_dig_overflow(char **content, size_t i, size_t *size, char is_str)
{
	char	*num;
	char	to_add;
	int		nb;

	if (!content || !*content)
		return ;
	num = *content;
	nb = 0;
	if (is_str)
		nb = 48;
	if (num[i] - nb > 9)
	{
		to_add = (num[i] - nb) / 10 + nb;
		num[i] = (num[i] - nb) % 10 + nb;
		if (!(num = ft_memalloc(++(*size))))
			exit(EXIT_FAILURE);
		ft_memcpy(num, *content, i);
		num[i] = to_add;
		ft_memcpy(num + i + 1, *content + i, *size - 1 - i);
		ft_strdel(content);
		*content = num;
	}
}

char		*pf_update_nums2str(char *str, char *content, size_t size)
{
	size_t	i;

	if (!content)
	{
		str[0] = '0';
		return (str + 1);
	}
	i = 0;
	while (i < size)
	{
		str[i] = content[i] + 48;
		++i;
	}
	return (str + i);
}
