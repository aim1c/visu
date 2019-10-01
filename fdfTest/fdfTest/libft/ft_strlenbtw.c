/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlenbtw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:22:02 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/06 16:29:48 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlenbtw(const char *s, char from, char end)
{
	size_t i;

	i = 0;
	while (*s != from && *s)
		s++;
	if (!*s)
		return (0);
	while (*s != end && *s)
	{
		s++;
		i++;
	}
	return (i);
}
