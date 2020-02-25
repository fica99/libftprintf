/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:12:31 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/25 22:56:55 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include "libft.h"

# define PRINTF_BUFF_SIZE 10000
# define TRUE 1
# define FALSE 0
# define ASCII_SIZE 128
typedef enum		e_pf_flags
{
	PF_FL_INIT = 0,
	PF_FL_HASH = 1,
	PF_FL_ZERO = 2,
	PF_FL_MINUS = 4,
	PF_FL_PLUS = 8,
	PF_FL_SPACE = 16,
	PF_FL_FWIDTH = 32,
}					t_pf_flags;

typedef enum		e_pf_mod_len
{
	PF_ML_INIT = 0,
	PF_ML_HH,
	PF_ML_H,
	PF_ML_L,
	PF_ML_LL,
	PF_ML_BL,
	PF_ML_J,
	PF_ML_Z,
	PF_ML_T,
}					t_pf_mod_len;

typedef struct		s_printf
{
	va_list			argptr;
	size_t			buff_len;
	size_t			i;
	size_t			malloc_len;
	t_pf_flags		flags;
	t_pf_mod_len	mod;
	size_t			width;
	size_t			prec;
	char			*buff;
}					t_printf;

/*
**					ft_printf.c
*/
int					ft_printf(const char *restrict format, ...);
/*
**					pf_parse.c
*/
void				pf_parse_string(const char *restrict format,
											t_printf *restrict pf);
/*
**					pf_tables.c
*/
t_pf_flags			*pf_flags_table(void);
t_pf_mod_len		*pf_mod_table(void);
#endif
