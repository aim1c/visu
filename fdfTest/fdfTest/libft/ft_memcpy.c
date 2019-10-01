/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 21:04:04 by lorippin          #+#    #+#             */
/*   Updated: 2018/11/26 16:34:36 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char			*str1;
	char			*str2;
	unsigned long	i;

	str1 = (char *)dst;
	str2 = (char *)src;
	i = n;
	while (n)
	{
		*str1 = *str2;
		str1++;
		str2++;
		n--;
	}
	return (dst);
}
