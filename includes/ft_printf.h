/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 22:12:31 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/07 13:28:07 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF
# define FT_PRINTF

# include <stdarg.h>
# include <limits.h>
# include <stdint.h>
# include <math.h>
# include "libft.h"

# define PRINTF_BUFF_SIZE 10000
# define TRUE 1
# define FALSE 0
# define ASCII_SIZE 128
# define LONG_DOUBLE_EXP 16383
# define INF_MANTIS 128
# define DEL_SIGN 127
# define MANTIS_LEN 64
# define LONG_DOUBLE_MALLOC_LEN 1000

typedef enum		e_pf_flags
{
	PF_FL_INIT = 0,
	PF_FL_HASH = 1,
	PF_FL_ZERO = 2,
	PF_FL_MINUS = 4,
	PF_FL_PLUS = 8,
	PF_FL_SPACE = 16,
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
	int				prec;
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
void				pf_spec_s(t_printf *restrict pf);
void				pf_spec_percent(t_printf *restrict pf);
void				pf_spec_int(t_printf *restrict pf);
void				pf_spec_p(t_printf *restrict pf);
/*
**					pf_spec_handlers2.c
*/
void				pf_spec_big_x(t_printf *restrict pf);
void				pf_spec_small_x(t_printf *restrict pf);
/*
**					pf_buff_managment.c
*/
void				pf_add_str(t_printf *restrict pf, char *str);
void				pf_check_mem(t_printf *restrict pf, const size_t add_len);
void				pf_add_symb(t_printf *restrict pf, char c, size_t res_len);
void				pf_add_str_2_buff(t_printf *restrict pf, const char *str,
															const size_t len);
char				pf_check_sign(t_printf *restrict pf, intmax_t nb);
/*
**					pf_convert.c
*/
intmax_t			pf_convert_nb(t_pf_mod_len mod, intmax_t num);
intmax_t			pf_convert_unb(t_pf_mod_len mod, intmax_t num);
/*
**					pf_handle_di.c
*/
void				pf_handle_di(t_printf *restrict pf, intmax_t nb, char *str);
/*
**					pf_handle_p.c
*/
void				pf_handle_p(t_printf *restrict pf, intmax_t nb, char *str);
/*
**					pf_handle_x.c
*/
void				pf_handle_x(t_printf *restrict pf, intmax_t nb, char *str, char is_big);
/*
**					pf_ltoa.c
*/
char				*ft_ultoa_base(uintmax_t n, int base, char cap);
char				*ft_iltoa(intmax_t num);
/*
**					pf_handle_small_f.c
*/
void				pf_spec_small_f(t_printf *restrict pf);
/*
**					pf_dtoi.c
*/
char				*pf_dtoi(long double num);
/*
**					pf_dtoi_exp_mantis.c
*/
void				pf_exp_mantis2str(char *str, short exp, unsigned long mantis);
/*
**					pf_dtoi_long_arith.c
*/
void				pf_carry(char *res, int size);
char				*pf_pow(short pow, short exp);
char				*pf_update_nums2str(char *str, char *num);
char				*pf_div_pow(char *num, short prev_exp, short exp, short pow);
/*
**					pf_dtoi_list.c
*/
void				pf_add_elem2list(char to_start, t_list **head, t_list *el);
t_list				*pf_get_last(t_list *head);
#endif
