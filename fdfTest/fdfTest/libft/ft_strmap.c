/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:05:20 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/03 14:02:47 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	mem_c(char const *s, char (*f)(char))
{
	int i;

	i = 0;
	while (*s)
		if (f(*s++))
			i++;
	return (i);
}

char		*ft_strmap(char const *s, char (*f)(char))
{
	char *new;
	char *rnew;

	if (s && f)
	{
		if (!(new = (char *)malloc(sizeof(char) * mem_c(s, f) + 1)))
			return (NULL);
		rnew = new;
		while (*s)
		{
			if ((*new = f(*s)))
				new++;
			s++;
		}
		*new = '\0';
		return (rnew);
	}
	return (NULL);
}
