/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_handle_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:44:39 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/29 00:15:03 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		pf_ltoa_rec(long num, char *str, int index)
{
	if (num >= 10)
		pf_ltoa_rec(num / 10, str, index - 1);
	str[index] = (num % 10) + '0';
}

static char		*ft_iltoa(intmax_t num)
{
	int			str_size;
	char		*new_str;
	short		sign;
	intmax_t	tmp;

	if (num == LONG_MIN)
		return (ft_strdup("9223372036854775808"));
	sign = (num < 0) ? -1 : 1;
	num *= sign;
	str_size = 1;
	if (num)
	{
		tmp = num;
		while ((tmp /= 10) > 0)
			++str_size;
	}
	if (!(new_str = (char *)malloc(sizeof(char) * (str_size + 1))))
		return (NULL);
	new_str[str_size] = '\0';
	pf_ltoa_rec(num, new_str, str_size - 1);
	return (new_str);
}

static char		pf_check_sign(t_printf *restrict pf, intmax_t nb, size_t *len, size_t *res_len)
{
	char		sign;

	if (nb < 0)
		sign = ('-');
	else if (pf->flags & PF_FL_PLUS)
		sign = ('+');
	else if (pf->flags & PF_FL_SPACE)
		sign = (' ');
	else
		return (0);
	++(*len);
	++(*res_len);
	return (sign);
}

static size_t	pf_pre(t_printf *restrict pf, intmax_t nb, size_t len)
{
	char		sign;
	size_t		res_len;

	res_len = ((int)len < pf->prec) ? pf->prec : len;
	sign = pf_check_sign(pf, nb, &len, &res_len);
	if (sign && (pf->flags & PF_FL_ZERO))
		pf->buff[pf->buff_len++] = sign;
	if (!(pf->flags & PF_FL_MINUS))
		pf_add_width(pf, res_len);
	if (sign && !(pf->flags & PF_FL_ZERO))
		pf->buff[pf->buff_len++] = sign;
	while (len++ < res_len)
		pf->buff[pf->buff_len++] = '0';
	return (res_len);
}

void			pf_handle_int(t_printf *restrict pf, intmax_t nb)
{
	char	*str;
	size_t	len;

	str = ft_iltoa(nb);
	len = ft_strlen(str);
	pf_check_mem(pf, pf->width + len + 1);
	len = pf_pre(pf, nb, len);
	pf_add_str_2_buff(pf, str, len);
	if (pf->flags & PF_FL_MINUS)
		pf_add_width(pf, len);
	ft_strdel(&str);
}
