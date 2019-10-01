/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/04 21:45:17 by lorippin          #+#    #+#             */
/*   Updated: 2018/12/04 23:11:23 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;

	list = NULL;
	if (alst && *alst)
	{
		list = *alst;
		while (list)
		{
			list = (*alst)->next;
			del((*alst)->content, (*alst)->content_size);
			(*alst)->next = NULL;
			free(*alst);
			*alst = list;
		}
		*alst = NULL;
	}
}
