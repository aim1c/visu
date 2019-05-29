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

#ifndef VISU_VISU_H
#define VISU_VISU_H

# include "libft/libft/libft.h"
# include "mlx/mlx.h"

typedef struct	s_image
{
	void 		*img_ptr;
	char		*ln;
	int			*lni;
	int			bits;
	int			endian;
	int			x_lin;
	int			y_lin;
}				t_img;

typedef struct	s_data
{
	t_list		*data;
	t_list		*data_head;
}				t_data;

typedef struct	s_mlx
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_data		*dat;
	int			x_lin;
	int			y_lin;
}				t_mlx;

#endif
