/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 23:24:07 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/05/30 00:33:23 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	render(t_sdl **s)
{
	SDL_RenderClear((*s)->renderer);
	SDL_RenderPresent((*s)->renderer);
}
void 	break_game_while(int *f, t_sdl **s)
{
	while (SDL_PollEvent(&(*s)->e) != 0)
	{
		if ((*s)->e.type == SDL_QUIT)
			*f = TRUE;
	}
}

int		close_sdl(t_mlx *m)
{
	SDL_DestroyWindow(m->sdl->win);
	SDL_DestroyRenderer(m->sdl->renderer);
	SDL_Quit();
}

int		main()
{
	t_mlx	*m;
	int		f = FALSE;
	if ((m = init_all()) == NULL)
		exit_warn("()");
	get_lst_data(&m->dat);
	SDL_Init(SDL_INIT_VIDEO);
	init_create(&m->sdl);
	while (!f)
	{
		render(&m->sdl);
		break_game_while(&f, &m->sdl);
	}
	close_sdl(m);
	return 0;
}