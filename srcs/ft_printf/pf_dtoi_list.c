/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_dtoi_list.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/07 13:22:24 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/07 13:27:57 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*pf_get_last(t_list *head)
{
	t_list	*tmp;

	tmp = head;
	if (!tmp)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}


void	pf_add_elem2list(char to_start, t_list **head, t_list *el)
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
