/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:43:59 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/06 17:01:04 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcap(char *str)
{
	char *new;

	new = str;
	while (!ft_isalpha(str) && str)
		str++;
	*str = toupper(*str);
	while (*str)
	{
		*str = tolower(*str);
		str++;
	}
	return (new);
}
