/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:43:46 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/30 11:52:25 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	free_vis(t_env *vis)
{
	SDL_FreeSurface(vis->surface);
	SDL_DestroyTexture(vis->texture);
	SDL_DestroyTexture(vis->texture);
	SDL_DestroyRenderer(vis->renderer);
	SDL_DestroyWindow(vis->win);
	TTF_CloseFont(vis->font);
	SDL_Quit();
	TTF_Quit();
	free(vis->map);
	free(vis);
}

void	draw(t_env *vis)
{
	read_input(vis);
	if (!vis->map)
		return ;
	mine_sweap(vis);
	draw_map(vis);
	score(vis);
	update_screen(vis);
}

int	main(void)
{
	t_env		*vis;
	SDL_Event	event;

	vis = (t_env *)ft_memalloc(sizeof(*vis));
	init_sdl(vis);
	SDL_FillRect(vis->surface, NULL, 0xFF363636);
	title(vis);
	vis->map = NULL;
	vis->map_x = -1;
	vis->map_y = -1;
	vis->pause = 1;
	vis->c1 = hex_to_sdl_color(PLAYER1);
	vis->c2 = hex_to_sdl_color(PLAYER2);
	update_screen(vis);
	while (!vis->quit)
	{
		while (SDL_PollEvent(&event))
			keys(vis, &event);
		if (!vis->pause)
			draw(vis);
	}
	free_vis(vis);
	return (0);
}
