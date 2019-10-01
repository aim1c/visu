/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 23:00:59 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/03 02:01:26 by ken              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *new;
	char *ret;

	if (!(new = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	ret = new;
	while (size--)
		*new++ = '\0';
	*new = '\0';
	return (ret);
}
