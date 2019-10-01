/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:52:38 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/04 21:30:23 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	returning(unsigned long long res, int m, int i)
{
	if ((res > 9223372036854775807 && m > 0) || (i == 18 && m > 0))
		return (-1);
	if ((res > 9223372036854775808U && m < 0) || (i == 18 && m < 0))
		return (0);
	return (res * m);
}

int			ft_atoi(const char *str)
{
	int					m;
	unsigned long long	res;
	int					i;

	m = 1;
	res = 0;
	i = 0;
	while (*str == '\t' || *str == '\n' || *str == '\v' ||
			*str == '\f' || *str == '\r' || *str == ' ')
		str++;
	if (*str == '-')
	{
		m = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str++ - '0');
		if (++i == 18 && (*str >= '0' && *str <= '9'))
			return (returning(res, m, i));
	}
	return (returning(res, m, ++i));
}
