/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memset.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 22:44:37 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/02 20:49:38 by ken              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	sim;
	unsigned char	*res;

	if (!len)
		return (b);
	res = (unsigned char *)b;
	sim = (unsigned char)c;
	while (len)
	{
		*res = sim;
		res++;
		len--;
	}
	return (b);
}
