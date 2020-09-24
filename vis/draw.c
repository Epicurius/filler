/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:27:39 by nneronin          #+#    #+#             */
/*   Updated: 2020/06/18 15:55:25 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "vis.h"
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

void		square(int s_x, int s_y, int size, t_info *game)
{
	int		y;
	int		x;
	int		tmp;

	y = 0;
	tmp = 0;
	while (y < (size * 4))
	{
		x = 0;
		while (x < (size * 4))
		{
			game->pic[x + tmp + ((s_y * WIDTH * 4) + (s_x * 4))] =
				game->rgb;
			game->pic[x + 1 + tmp + ((s_y * WIDTH * 4) + (s_x * 4))] =
				game->rgb >> 8;
			game->pic[x + 2 + tmp + ((s_y * WIDTH * 4) + (s_x * 4))] =
				game->rgb >> 16;
			x += 4;
		}
		y += 4;
		tmp += (WIDTH * 4);
	}
}

void		draw_map(t_info *game)
{
	int	y;
	int	x;
	int	size;
	int	offset;

	size = ((WIDTH / 2) / (game->map_x)) - 2;
	offset = ((HEIGHT - (game->map_y * size) - (game->map_y * 2)) / 2);
	y = -1;
	while (++y < game->map_y)
	{
		x = -1;
		while (++x < game->map_x)
		{
			if (game->map[y][x] > 0 && game->heat == 1)
				game->rgb = heat_color(game->map[y][x], game);
			else
				game->rgb = EMPTY;
			if (game->map[y][x] == -1 || game->map[y][x] == -2)
				game->rgb = game->map[y][x] == -1 ? PLAYER1 : PLAYER2;
			else if (game->map[y][x] == -3 || game->map[y][x] == -4)
				game->rgb = game->map[y][x] == -3 ? 0x00ffff : 0xffaa00;
			square((x * size) + (x * 2) + 2, (y * size) + (y * 2) + offset,
				size, game);
		}
	}
}

void		draw_graph(t_info *game)
{
	int		y;
	int		x;
	int		size;

	size = 3;
	y = -1;
	while (++y < Y_GRAPH)
	{
		x = -1;
		while (++x < X_GRAPH)
		{
			if (game->graph[y][x] == 0)
				game->rgb = 0x656565;
			else if (game->graph[y][x] == 1)
				game->rgb = PLAYER1;
			else if (game->graph[y][x] == 2)
				game->rgb = PLAYER2;
			else if (game->graph[y][x] == 3)
				game->rgb = 0xAADA00;
			square((x * size) + (x * 2) + 670, (y * size) + (y * 2) + 165,
				size, game);
		}
	}
}

int			right_side(int moves, t_info *game)
{
	int move;

	move = ((game->s1 + game->s2) / ((game->map_y * game->map_x) / X_GRAPH));
	if (move < X_GRAPH && move > moves)
	{
		moves = move;
		graph(game->s1, move, 1, game);
		graph(game->s2, move, 2, game);
	}
	draw_graph(game);
	mlx_string_put(game->mlx, game->win, (WIDTH / 2) + 150, (HEIGHT / 6),
		PLAYER1, game->p1);
	mlx_string_put(game->mlx, game->win, (WIDTH / 2) + 330, (HEIGHT / 6),
		PLAYER2, game->p2);
	mlx_string_put(game->mlx, game->win, (WIDTH / 2) + 150, (HEIGHT / 5),
		PLAYER1, ft_itoa(game->s1));
	mlx_string_put(game->mlx, game->win, (WIDTH / 2) + 330, (HEIGHT / 5),
		PLAYER2, ft_itoa(game->s2));
	return (moves);
}

int			draw(t_info *game)
{
	int moves;

	moves = 0;
	if (game->pause == 0)
	{
		game->pic = mlx_get_data_addr(game->img, &(game->bits_per_pixel),
			&(game->size_line), &(game->endian));
		read_input(game);
		mine_sweap(game, 0, 0);
		background(game);
		draw_map(game);
		moves = right_side(moves, game);
		mlx_put_image_to_window(game->mlx, game->win, game->img, 0, 0);
		mlx_destroy_image(game->mlx, game->img);
		game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	}
	return (0);
}
