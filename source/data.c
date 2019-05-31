/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aim1c <aim1c@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 23:21:35 by aim1c             #+#    #+#             */
/*   Updated: 2019/05/29 23:30:29 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_mlx	*init_all(void)
{
	t_mlx	*m;

	m = (t_mlx *)malloc(sizeof(t_mlx) + 1);
	m->dat = (t_data *)malloc(sizeof(t_data) + 1);
	m->sdl = (t_sdl *)malloc(sizeof(t_sdl) + 1);
	sdl_to_null(&m->sdl);
	return (m);
}

void	exit_warn(char *ln)
{
	ft_printf(ln);
	exit(EXIT_SUCCESS);
}

void	get_lst_data(t_data **d)
{
	char	*ln;

	(*d)->data = NULL;
	(*d)->data_head = NULL;
	while (ft_gnl(0, &ln) > 0)
	{
		if ((*d)->data_head == 0)
		{
			(*d)->data_head = ft_lstnew(ln, ft_strlen(ln) + 1);
			(*d)->data = (*d)->data_head;
		}
		else
		{
			(*d)->data->next = ft_lstnew(ln, ft_strlen(ln) + 1);
			(*d)->data = (*d)->data->next;
		}
	}
}