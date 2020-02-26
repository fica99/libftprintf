/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:12:31 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/26 21:53:48 by aashara-         ###   ########.fr       */
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
void				*pf_spec_table(const char c);
/*
**					pf_spec_handlers.c
*/
void				pf_spec_c(t_printf *restrict pf);
/*
**					pf_buff_managment.c
*/
void				pf_add_width(t_printf *restrict pf, const size_t len);
void				pf_add_char(t_printf *restrict pf, const char c);
void				pf_check_mem(t_printf *restrict pf, const size_t add_len);
#endif
