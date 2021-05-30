/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brains.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:20:10 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/30 11:20:23 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	largest(int x, int y, int combo, t_info *game)
{
	game->final_x = x;
	game->final_y = y;
	game->value = combo;
}

static void	is_space(int map_x, int map_y, int combo, t_info *game)
{
	int		i;
	t_i2	p;
	int		coord;

	i = 0;
	p.y = -1;
	while (++p.y < game->piece_y)
	{
		p.x = -1;
		while (++p.x < game->piece_x)
		{
			if (game->piece[p.y * game->piece_x + p.x] != 1)
				continue ;
			if ((p.y + map_y) >= game->map_y || (p.x + map_x) >= game->map_x || (p.y + map_y) < 0 || (p.x + map_x) < 0)
				return ;
			coord = (p.y + map_y) * game->map_x + (p.x + map_x);
			if (i == 0 && game->map[coord] == game->me)
				i += 1;
			else if (game->map[coord] < 0)
				return ;
			combo += game->map[coord];
		}
	}
	if (i == 1 && combo < game->value)
		largest(map_x, map_y, combo, game);
}

void	surround(t_info *game)
{
	int	y;
	int	x;

	game->value = 2147483647;
	y = (game->piece_y + 1) * -1;
	while (++y < game->map_y)
	{
		x = (game->piece_x + 1) * -1;
		while (++x < game->map_x)
			is_space(x, y, 0, game);
		if (game->value == game->piece_area)
			return ;
	}
}

static int	proximity_calc(int map_x, int map_y, t_info *game)
{
	int	x;
	int	y;
	int	value;
	int	min_value;

	y = -1;
	min_value = 2147483647;
	while (++y < game->map_y)
	{
		x = -1;
		while (++x < game->map_x)
		{
			if (game->map[y * game->map_x + x] == game->him)
			{
				value = pos(y - map_y) + pos(x - map_x);
				if (value < min_value)
				{
					if (value <= 1)
						return (value);
					min_value = value;
				}
			}
		}
	}
	return (min_value);
}

void	mine_sweap(t_info *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->map_y)
	{
		x = -1;
		while (++x < game->map_x)
		{
			if (game->map[y * game->map_x + x] == 0)
				game->map[y * game->map_x + x] = proximity_calc(x, y, game);
		}
	}
}
