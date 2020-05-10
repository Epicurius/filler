
#include "filler.h"

void	largest(int y, int x, int combo, t_info *game)
{
	game->fin[0] = y;
	game->fin[1] = x;
	game->value = combo;
}

void	is_space(int y, int x, int combo, t_info *game)
{
	int a;
	int b;
	int i;

	i = 0;
	a = -1;
	while ((game->piece_y - 1) > a++)
	{
		b = -1;
		while ((game->piece_x - 1) > b++)
		{
			if (game->piece[a][b] == 1)
			{
				if ((a + y) >= game->map_y || (b + x) >= game->map_x)
					return ;
				if (i == 0 && game->map[y + a][x + b] == game->my_num)
					i += 1;
				else if (game->map[y + a][x + b] < 0 || i > 1)
					return ;
				combo += game->map[y + a][x + b];
			}
		}
	}
	(i == 1 && combo < game->value) ? largest(y, x, combo, game) : 0;
}

int	surround(t_info *game)
{
	int y;
	int x;

	y = 0;
	while (y < game->map_y)
	{
		x = 0;
		while (x < game->map_x)
		{
			is_space(y, x, 0, game);
			x++;
		}
		y++;
	}
	return (0);
}

int	proximity_calc(int y, int x, t_info *game)
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

int	mine_sweap(t_info *game)
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
			x++;
		}
		y++;
	}
	return (0);
}
