/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:55:55 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/03 22:02:38 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

typedef unsigned char byte;

static long double	pf_swap_bytes(long double num)
{
	unsigned char	*bites;
	unsigned char	*res_bites;
	long double		res;
	size_t			i;

	bites = (unsigned char*)&num;
	res_bites = (unsigned char*)&res;
	i = 0;
	while (i < 10) {
		res_bites[i] = bites[9 - i];
		++i;
	}
	return (res);
}


int		main(void)
{
	long double		num = 12e50;
	unsigned char	*line = (unsigned char*)&num;

	for (int j = 0; j < 10; ++j) {
		byte b = line[j];
		for (int i = 7; i >= 0; i--) {
			printf("%c", (b & 1 << i) ? '1' : '0');
		}
	}
	printf("\n");
	num = pf_swap_bytes(num);
	for (int j = 0; j < 10; ++j) {
		byte b = line[j];
		for (int i = 7; i >= 0; i--) {
			printf("%c", (b & 1 << i) ? '1' : '0');
		}
	}
	printf("\n");
	ft_printf("ft_printf - %Lf\n", 12e-100);
	printf("printf - %Lf\n", (long double)12e300);
	return 0;
}
