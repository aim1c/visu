/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:53:41 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/03 01:20:38 by ken              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char		*ptr;
	const char	*nptr;

	nptr = needle;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack)
	{
		if (*needle == *haystack)
		{
			ptr = (char *)haystack;
			while (*needle && *needle == *haystack)
			{
				needle++;
				haystack++;
			}
			if (!(*needle))
				return (ptr);
			haystack = ptr;
			needle = nptr;
		}
		haystack++;
	}
	return (NULL);
}
