/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 17:01:17 by lorippin          #+#    #+#             */
/*   Updated: 2018/11/29 19:11:50 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;

	if (!(new = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	if (s && len)
	{
		new[len] = '\0';
		while ((int)--len >= 0)
			*(new + len) = *(s + start + len);
	}
	return (new);
}
