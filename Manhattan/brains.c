
#include "fillit.h"
#include "./libft/libft.h"

int 	is_space(int y, int x, t_info *game)
{
	int a;
	int b;
	int i = 0;
	int combo;

	combo = 0;
	a = 0;
	while (game->piece_y > a)
	{
		b = 0;
		while (game->piece_x > b)
		{
			if (game->piece[a][b] == 1)
			{
				if ((a + y) >= game->map_y || (b + x) >= game->map_x)
					return (1);
				combo += game->map[y + a][x + b];
				// prioritize 5
				if (i == 0 && game->map[y + a][x + b] == game->my_num)
					i += 1;
				else if (game->map[y + a][x + b] < 0 || i > 1)
					return (1);
			}
			b++;
		}
		a++;
	}
	if (i == 1 && combo < game->value)
	{
		game->fin[0] = y;
		game->fin[1] = x;
		game->value = combo;
		return (0);
	}
	return (1);
}

int		surround(t_info *game)
{
	int y;
	int x;

	y = 0;
	while (y < game->map_y)// && (game->piece_y + y) <= game->map_y) //moove
	{
		x = 0;
		while (x < game->map_x)// && (game->piece_x + x) <= game->map_x)
		{
			is_space(y, x, game); // return check
			x++;
		}
		y++;
	}
	return (0);
}

int		proximity_calc(int y, int x, t_info *game)
{
	int a;
	int b;
	int value;
	int min_value;

	a = 0;
	min_value = 2147483647;
	while (a < game->map_y)
	{
		b = 0;
		while (b < game->map_x)
		{
			if (game->map[a][b] == (game->my_num == -1 ? -2 : -1))
			{
				value = pos(a - y) + pos(b - x);
				if (value < min_value)
					min_value = value;
			}
			b++;
		}
		a++;
	}
	return (min_value);
}

int		mine_sweap(t_info *game)
{
	int y;
	int x;

	y = 0;	
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			if (game->map[y][x] == 0)
				game->map[y][x] = proximity_calc(y, x, game);
			if (game->map[y][x] == 1)
				game->map[y][x] = 4;
			else if (game->map[y][x] == 2)
				game->map[y][x] = 3;
			else if (game->map[y][x] == 3)
				game->map[y][x] = 2;
			else if (game->map[y][x] == 4)
				game->map[y][x] = 1;
			x++;
		}
		y++;
	}
	return (0);
}
