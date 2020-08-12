/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 21:55:55 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/13 01:54:15 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

long double randfrom(long double min, long double max)
{
	long double range = (max - min);
	long double div = RAND_MAX / range;
	return min + (rand() / div);
}

int		main(void)
{
	long double	tmp;
	int			i;

	i = 0;
	while (i < 1)
	{
		tmp = randfrom(-1000000.0, 1000000.0);
		ft_printf("%f\n",tmp);
		printf("%f\n\n", tmp);
		++i;
	}
	return 0;
}
