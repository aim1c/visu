/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:26:11 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/05 23:38:30 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char		*ptr;
	const char	*nptr;
	int			i;

	nptr = needle;
	if (!*needle)
		return ((char *)haystack);
	while (*haystack && ((int)len-- + 1))
	{
		if (*needle == *haystack)
		{
			i = (int)len;
			ptr = (char *)haystack;
			while (*needle && *needle++ == *haystack++ && ((int)len-- + 1))
				if (!(*needle))
					return (ptr);
			haystack = ptr;
			len = (size_t)i;
			needle = nptr;
		}
		haystack++;
	}
	return (NULL);
}
