/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:03:03 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/03 14:05:25 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		len;
	char	*rnew;

	rnew = NULL;
	if (s)
	{
		i = 0;
		len = (int)ft_strlen(s) - 1;
		while (s[i] == ' ' || s[i] == '\n' || s[i] == '\t')
			i++;
		if (i == len + 1)
			return (ft_strnew(0));
		while (s[len] == ' ' || s[len] == '\n' || s[len] == '\t')
			len--;
		if (!(new = (char *)malloc(sizeof(char) * (len - i) + 2)))
			return (NULL);
		rnew = new;
		while (i <= len)
			*new++ = s[i++];
		*new = '\0';
	}
	return (rnew);
}
