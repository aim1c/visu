/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:24:31 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/03 14:04:41 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *save;
	char d;

	save = NULL;
	while ((d = *s))
	{
		if (d == c)
			save = (char *)s;
		s++;
	}
	if (d == c)
		return ((char *)s);
	return (save);
}
