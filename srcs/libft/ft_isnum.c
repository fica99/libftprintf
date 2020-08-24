/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnum.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aashara- <aashara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/24 16:21:53 by aashara-          #+#    #+#             */
/*   Updated: 2020/08/24 16:22:05 by aashara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isnum(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (i == 0)
		{
			if (str[i] == '+' || str[i] == '-')
			{
				++i;
				if (!str[i])
					return (0);
				continue ;
			}
		}
		if (!ft_isdigit(str[i]))
			return (0);
		++i;
	}
	return (1);
}
