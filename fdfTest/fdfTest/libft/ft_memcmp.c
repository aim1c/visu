/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 21:25:59 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/06 12:02:43 by ken              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char *ss1;
	unsigned char *ss2;

	ss1 = (unsigned char *)s1;
	ss2 = (unsigned char *)s2;
	if (!s1 && !s2)
		return (0);
	while ((*ss1 == *ss2) && --n)
	{
		ss1++;
		ss2++;
	}
	if (n == 0)
		return (0);
	return (*ss1 - *ss2);
}
