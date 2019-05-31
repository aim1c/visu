/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsnow-be <fsnow-be@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 23:24:07 by fsnow-be          #+#    #+#             */
/*   Updated: 2019/05/31 14:20:23 by aim1c            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visu.h"

void	text(t_sdl	**s, char *t, int size_f, int x, int y, SDL_Color col)
{
	TTF_Font	*font = TTF_OpenFont("../font.ttf", size_f);
	SDL_Surface *text = TTF_RenderUTF8_Blended(font, t, col);
	SDL_Texture *texture = SDL_CreateTextureFromSurface((*s)->renderer, text);
	SDL_FreeSurface(text);
	text = NULL;
	SDL_Rect dest;
	dest.x = x;
	dest.y = y;

	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);
	SDL_RenderCopy((*s)->renderer, texture, NULL, &dest);
	SDL_DestroyTexture(texture);
	texture = NULL;
	TTF_CloseFont(font);
}

void	render(t_sdl **s)
{
	SDL_SetRenderDrawColor((*s)->renderer, 255, 102, 0, 1);
	SDL_RenderClear((*s)->renderer);
	draw_lem_in_block(s);
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
	TTF_Quit();
	exit(EXIT_SUCCESS);
	return (1);
}

void	let_start(int *en, int *f, t_sdl **s)
{
		SDL_SetRenderDrawColor((*s)->renderer, 255, 102, 0, 1);
		SDL_RenderClear((*s)->renderer);
		text(s, "Enter any button...", 72, 350, 300, MAIN_TEXT_COL);
		SDL_RenderPresent((*s)->renderer);
		while (SDL_PollEvent(&(*s)->e) != 0)
		{
			if ((*s)->e.type == SDL_KEYDOWN)
				*en = 1;
			if ((*s)->e.type == SDL_QUIT)
			{
				*en = 1;
				*f = 1;
			}
		}
}

int		main()
{
	t_mlx	*m;
	int		f = FALSE;
	int		en = FALSE;

	if ((m = init_all()) == NULL)
		exit_warn("()");
	get_lst_data(&m->dat);
	SDL_Init(SDL_INIT_VIDEO);
	TTF_Init();
	init_create(&m->sdl);
	while (!en)
		let_start(&en, &f, &m->sdl);
	while (!f)
	{
		render(&m->sdl);
		break_game_while(&f, &m->sdl);
	}
	close_sdl(m);
	return 0;
}