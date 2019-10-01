/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lorippin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 21:11:08 by lorippin          #+#    #+#             */
/*   Updated: 2019/03/09 21:19:46 by lorippin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_rotate	*rotate_init(void)
{
	t_rotate *r;

	if (!(r = malloc(sizeof(t_rotate))))
		exit(EXIT_FAILURE);
	r->x = 0;
	r->y = 0;
	r->z = 0;
	return (r);
}

static t_fdf	*fdf_init(void)
{
	t_fdf *fdf;

	if (!(fdf = malloc(sizeof(t_fdf))))
		exit(EXIT_FAILURE);
	fdf->mlx = mlx_init();
	fdf->win = mlx_new_window(fdf->mlx, WIDTH, HIGHT, "FDF");
	fdf->points = NULL;
	fdf->vecs = NULL;
	fdf->rotate = rotate_init();
	fdf->scale = 20;
	fdf->shiftx = WIDTH / 2;
	fdf->shifty = HIGHT / 2;
	fdf->maxz = 0;
	fdf->minz = 0;
	return (fdf);
}

t_fdf			*fdf_instance(void)
{
	static t_fdf *fdf;

	if (!fdf)
		fdf = fdf_init();
	return (fdf);
}
