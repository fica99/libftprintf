/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:51:10 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/25 22:56:38 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_pf_flags		*pf_flags_table(void)
{
	static char			is_init;
	static t_pf_flags	table[ASCII_SIZE];

	if (!is_init)
	{
		table['#'] = PF_FL_HASH;
		table['-'] = PF_FL_MINUS;
		table['0'] = PF_FL_ZERO;
		table['+'] = PF_FL_PLUS;
		table[' '] = PF_FL_SPACE;
		is_init = TRUE;
	}
	return (table);
}

t_pf_mod_len		*pf_mod_table(void)
{
	static char			is_init;
	static t_pf_mod_len	table[ASCII_SIZE];

	if (!is_init)
	{
		table['l'] = PF_ML_L;
		table['L'] = PF_ML_BL;
		table['h'] = PF_ML_H;
		table['j'] = PF_ML_J;
		table['z'] = PF_ML_Z;
		table['t'] = PF_ML_Z;
		is_init = TRUE;
	}
	return (table);
}
