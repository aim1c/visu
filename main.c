/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 23:24:07 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/02/12 01:30:27 by fsnow-be         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

t_mlx	*init_all(void)
{
	t_mlx	*m;

	m = (t_mlx *)malloc(sizeof(t_mlx) + 1);
	m->dat = (t_data *)malloc(sizeof(t_data) + 1);
	m->img = (t_img *)malloc(sizeof(t_img) + 1);
	return (m);
}

void	exit_warn(char *ln)
{
	ft_printf(ln);
	exit(EXIT_SUCCESS);
}

int		key_hook(int c, t_mlx *m)
{
	if (c == 53)
		exit_warn("esc");
	return (0);
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

void	render(t_mlx *m)
{

}

int		main()
{
	t_mlx	*m;

	if ((m = init_all()) == NULL)
		exit_warn("()");
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, 1000, 1000, "visu");
	get_lst_data(&m->dat);
	render(m);
	mlx_key_hook(m->win, key_hook, m);
	mlx_loop(m->mlx);
	return 0;
}