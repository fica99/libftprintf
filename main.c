/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:55:55 by aashara-          #+#    #+#             */
/*   Updated: 2020/07/31 01:20:38 by aashara-         ###   ########.fr       */
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
	long double		num = 0.0;
	unsigned char	*line = (unsigned char*)&num;

	for (int j = 0; j < 10; ++j) {
		byte b = line[j];
		for (int i = 7; i >= 0; i--) {
			printf("%c", (b & 1 << i) ? '1' : '0');
		}
	}
	printf("\n");
	ft_printf("ft_printf - %f\n", 0.0);
	printf("printf - %f\n", 0.0);
	num = pf_swap_bytes(num);
	for (int j = 0; j < 10; ++j) {
		byte b = line[j];
		for (int i = 7; i >= 0; i--) {
			printf("%c", (b & 1 << i) ? '1' : '0');
		}
	}
	printf("\n");
	return 0;
}
// 	printf("%f\n", 48.0);
// 	return (0);
// }
