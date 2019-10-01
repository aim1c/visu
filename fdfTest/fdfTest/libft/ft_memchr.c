/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sschuppe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 16:38:40 by sschuppe          #+#    #+#             */
/*   Updated: 2019/03/09 21:56:05 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	d;
	size_t			i;
	unsigned char	*ss;

	i = 0;
	d = (unsigned char)c;
	ss = (unsigned char *)s;
	if (n == 0)
		return (NULL);
	while (i < n)
	{
		if (ss[i] == d)
			return (ss + i);
		i++;
	}
	return (NULL);
}
