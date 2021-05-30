/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 10:46:45 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/30 11:48:37 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	title(t_env *vis)
{
	SDL_Surface	*tmp;
	SDL_Rect	dstr;
	TTF_Font	*font;

	font = TTF_OpenFont("Tetris.ttf", 50);
	if (!vis->font)
		error_msg("Could not open font: %s\n", TTF_GetError());
	tmp = TTF_RenderText_Blended(font, "FILLER", hex_to_sdl_color(0xff0f0f0f));
	dstr = (SDL_Rect){W / 2 + 125, H / 6, tmp->w, tmp->h};
	SDL_BlitSurface(tmp, NULL, vis->surface, &dstr);
	SDL_FreeSurface(tmp);
	TTF_CloseFont(font);
}

void	score(t_env *vis)
{
	char		*str;
	SDL_Surface	*surf;
	SDL_Rect	dstr;

	str = ft_itoa(vis->p1);
	surf = TTF_RenderText_Blended(vis->font, str, vis->c1);
	dstr = (SDL_Rect){W / 2 + 125, H / 2.5, surf->w, surf->h};
	SDL_FillRect(vis->surface, &dstr, 0xFF363636);
	SDL_BlitSurface(surf, NULL, vis->surface, &dstr);
	free(str);
	SDL_FreeSurface(surf);
	str = ft_itoa(vis->p2);
	surf = TTF_RenderText_Blended(vis->font, str, vis->c2);
	dstr = (SDL_Rect){W / 2 + 400, H / 2.5, surf->w, surf->h};
	SDL_FillRect(vis->surface, &dstr, 0xFF363636);
	SDL_BlitSurface(surf, NULL, vis->surface, &dstr);
	free(str);
	SDL_FreeSurface(surf);
}
