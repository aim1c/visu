/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcurlist.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 15:59:53 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/06 16:15:02 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_getcurlist(t_list *list, int elem)
{
	while (list && elem--)
		list = list->next;
	if (elem)
		return (NULL);
	return (list);
}
