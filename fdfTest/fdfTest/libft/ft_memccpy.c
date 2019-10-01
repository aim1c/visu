/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 23:44:28 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/02 21:04:56 by ken              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	unsigned char	d;

	d = (unsigned char)c;
	str1 = (unsigned char *)dst;
	str2 = (unsigned char *)src;
	while (n)
	{
		if (*str2 == d)
		{
			*str1 = *str2;
			break ;
		}
		*str1 = *str2;
		str1++;
		str2++;
		n--;
	}
	if (n != 0)
		return (str1 + 1);
	return (NULL);
}
