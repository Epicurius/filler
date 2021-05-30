/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 11:24:16 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/30 11:47:49 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	update_screen(t_env *vis)
{
	if (SDL_UpdateTexture(vis->texture, NULL, vis->surface->pixels,
			vis->surface->pitch))
		error_msg("Failed to update screen: %s\n", SDL_GetError());
	if (SDL_RenderCopy(vis->renderer, vis->texture, NULL, NULL))
		error_msg("SDL_RenderCopy error: %s\n", SDL_GetError());
	SDL_RenderPresent(vis->renderer);
}

void	keys(t_env *vis, SDL_Event *event)
{
	if (event->type == SDL_QUIT)
		vis->quit = 1;
	if (event->type == SDL_KEYDOWN)
	{
		if (event->key.keysym.sym == SDLK_p)
			vis->pause = vis->pause == 0;
		else if (event->key.keysym.sym == SDLK_h)
		{
			vis->heat = vis->heat == 0;
			init_map(vis);
		}
		else if (event->key.keysym.sym == SDLK_q
			|| event->key.keysym.sym == SDLK_ESCAPE)
			vis->quit = 1;
	}
}

void	init_sdl(t_env *vis)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO))
		error_msg("Could not init SDL: %s\n", SDL_GetError());
	if (TTF_Init())
		error_msg("Could not init TTF: %s\n", SDL_GetError());
	vis->win = SDL_CreateWindow("Filler Visualiser", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, W, H, SDL_WINDOW_ALWAYS_ON_TOP);
	if (!vis->win)
		error_msg("Could not create window: %s\n", SDL_GetError());
	vis->surface = SDL_CreateRGBSurfaceWithFormat(0, W, H,
			32, SDL_PIXELFORMAT_ARGB8888);
	if (!vis->surface)
		error_msg("Could not create surface: %s\n", SDL_GetError());
	vis->renderer = SDL_CreateRenderer(vis->win, -1,
			SDL_RENDERER_TARGETTEXTURE);
	if (!vis->renderer)
		error_msg("Could not create renderer: %s\n", SDL_GetError());
	vis->texture = SDL_CreateTexture(vis->renderer, SDL_PIXELFORMAT_ARGB8888,
			SDL_TEXTUREACCESS_STREAMING, vis->surface->w, vis->surface->h);
	if (!vis->texture)
		error_msg("Could not create texture: %s\n", SDL_GetError());
	vis->font = TTF_OpenFont("Digital.ttf", 50);
	if (!vis->font)
		error_msg("Could not open font: %s\n", TTF_GetError());
}
