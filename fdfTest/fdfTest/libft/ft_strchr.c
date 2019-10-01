/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 20:33:50 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/03 00:14:34 by ken              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char k;

	k = (char)c;
	while (*s)
	{
		if (*s == k)
			return ((char *)s);
		s++;
	}
	if (*s == k)
		return ((char *)s);
	return (NULL);
}
