/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 23:24:07 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/05/30 00:31:33 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISU_VISU_H
#define VISU_VISU_H

# include "libft/libft/libft.h"
# include "mlx/mlx.h"
# include <SDL2/SDL.h>

# define WI 1280
# define HI 720

/*
** -------------------------- Struct with SDL2 structs -------------------------
 * ------------win		-> main window
 * ------------renderer	-> backgrond and reload images
 * ------------e		-> struct with events
*/

typedef struct		s_sdl
{
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Event		e;
}					t_sdl;

/*
** -------------------------- Save data, from lem_in ---------------------------
*/

typedef struct		s_data
{
	t_list			*data;
	t_list			*data_head;
}					t_data;

/*
** -------------------------- Main struct --------------------------------------
*/

typedef struct		s_mlx
{
	t_sdl			*sdl;
	t_data			*dat;
}					t_mlx;

t_mlx				*init_all(void);
void				exit_warn(char *ln);
void				get_lst_data(t_data **d);

/*
** -------------------------- SDL ----------------------------------------------
*/
void				sdl_to_null(t_sdl **s);
void				init_create(t_sdl **s);
#endif
