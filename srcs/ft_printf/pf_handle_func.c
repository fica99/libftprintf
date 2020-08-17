/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olegmulko <olegmulko@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/17 14:30:05 by olegmulko         #+#    #+#             */
/*   Updated: 2020/08/17 15:34:06 by olegmulko        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_align_to_width(t_printf *restrict pf, char c, t_len_opts *len_opts)
{
	size_t	i;

	i = len_opts->ac_len;
	while (i < len_opts->w_len)
	{
		pf->buff[(pf->buff_len)++] = c;
		i++;
	}
}

void	pf_align_to_accuracy(t_printf *restrict pf, char c, t_len_opts *len_opts)
{
	size_t	i;

	i = len_opts->num_len;
	while (i < len_opts->ac_len)
	{
		pf->buff[(pf->buff_len)++] = c;
		i++;
	}
}
