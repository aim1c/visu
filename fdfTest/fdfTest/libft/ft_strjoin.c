/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:23:49 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/03 02:23:17 by ken              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	char	*rnew;
	size_t	i;

	rnew = NULL;
	if (s1 && s2)
	{
		i = ft_strlen(s1) + ft_strlen(s2);
		if (!(new = (char *)malloc(sizeof(char) * i + 1)))
			return (NULL);
		rnew = new;
		if (s1 && s2)
		{
			while (*s1)
				*new++ = *s1++;
			while (*s2)
				*new++ = *s2++;
			*new = '\0';
		}
	}
	return (rnew);
}
