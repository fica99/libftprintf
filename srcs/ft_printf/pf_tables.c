/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_tables.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 21:51:10 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/27 22:35:30 by aashara-         ###   ########.fr       */
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
		table['O'] = PF_FL_ZERO;
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

void				*pf_spec_table(const char c)
{
	static char			is_init;
	static void			*table[ASCII_SIZE];

	if (!is_init)
	{
		table['c'] = (void*)&pf_spec_c;
		table['%'] = (void*)&pf_spec_percent;
		table['s'] = (void*)&pf_spec_s;
		table['d'] = (void*)&pf_spec_int;
		table['i'] = (void*)&pf_spec_int;
		table['D'] = (void*)&pf_spec_int;
		// table['p'] = ;
		// table['o'] = ;
		// table['u'] = ;
		// table['x'] = ;
		// table['X'] = ;
		// table['f'] = ;
		// table['e'] = ;
		// table['g'] = ;
		is_init = TRUE;
	}
	return (table[(size_t)c]);
}
