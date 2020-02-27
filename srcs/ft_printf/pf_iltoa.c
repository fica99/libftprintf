/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_iltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/27 22:44:39 by aashara-          #+#    #+#             */
/*   Updated: 2020/02/27 22:50:37 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char		*ft_strmemal(intmax_t num, size_t *size_n)
{
	if (num == LONG_MIN)
	{
		*size_n = 0;
		return (ft_strdup("-9223372036854775808"));
	}
	*size_n = 1;
	if (num < 0)
		++(*size_n);
	while ((num = num / 10))
		++(*size_n);
	return (ft_strnew(*size_n));
}

char			*ft_iltoa(intmax_t n)
{
	size_t		size_n;
	char		*str;
	char		*ret;

	if (!(str = ft_strmemal(n, &size_n)))
		exit(1);
	ret = str;
	if (n < 0 && size_n > 0)
	{
		*str++ = '-';
		n *= -1;
		--size_n;
	}
	while (size_n--)
	{
		str[size_n] = '0' + n % 10;
		n /= 10;
	}
	return (ret);
}
