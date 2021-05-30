/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/30 11:26:21 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/30 11:42:59 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

SDL_Color	hex_to_sdl_color(int hex)
{
	SDL_Color	color;

	color.a = hex >> 24;
	color.r = hex >> 16;
	color.g = hex >> 8;
	color.b = hex;
	return (color);
}

void	square(int s_x, int s_y, t_env *vis)
{
	int		y;
	int		x;
	Uint32	*pix;

	pix = vis->surface->pixels;
	y = 0;
	while (y < vis->size)
	{
		x = 0;
		while (x < vis->size)
		{
			pix[(y + s_y) *W + (x + s_x)] = vis->rgb;
			x += 1;
		}
		y += 1;
	}
}

static int	heat_color(int value, int max)
{
	int		r;
	int		g;
	int		b;
	float	ratio;

	ratio = (value - 1.0) / ((max - 1.0) / 2.0);
	b = 255 * (ratio - 1);
	r = 255 * (1 - ratio);
	if (b < 0)
		b = 0;
	if (r < 0)
		r = 0;
	g = 255 - b - r;
	if (g < 0)
		g *= -1;
	return ((r & 0xFF) << 16 | (g & 0xFF) | (b & 0xFF));
}

void	draw_map(t_env *vis)
{
	int	y;
	int	x;

	y = -1;
	while (++y < vis->map_y)
	{
		x = -1;
		while (++x < vis->map_x)
		{
			if (vis->map[y * vis->map_x + x] == -1)
				vis->rgb = PLAYER1;
			else if (vis->map[y * vis->map_x + x] == -2)
				vis->rgb = PLAYER2;
			else if (vis->map[y * vis->map_x + x] == -3)
				vis->rgb = 0x00ffff;
			else if (vis->map[y * vis->map_x + x] == -4)
				vis->rgb = 0xffaa00;
			else if (vis->heat)
				vis->rgb = heat_color(vis->map[y * vis->map_x + x], vis->max);
			else
				continue ;
			square((x * vis->size) + (x * 2) + 2,
				(y * vis->size) + (y * 2) + vis->offset, vis);
		}
	}
}
