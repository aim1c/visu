/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:31:43 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/06 16:38:21 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_wordcount(const char *s, char sep)
{
	size_t i;

	i = 0;
	if (!s)
		return (0);
	while (*s)
	{
		while (*s == sep)
			s++;
		if (*s && *s != sep)
			i++;
		while (*s != sep && *s)
			s++;
	}
	return (i);
}
