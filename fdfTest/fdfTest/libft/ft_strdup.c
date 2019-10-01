/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 22:04:15 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/03 14:02:16 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		lenght;
	char	*str;

	lenght = ft_strlen((char *)s1);
	if (!(str = malloc(sizeof(char) * lenght + 1)))
		return (NULL);
	while (*s1)
	{
		*str = *s1;
		str++;
		s1++;
	}
	*str = '\0';
	return (str - lenght);
}
