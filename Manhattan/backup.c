int		placement(t_info *game)
{
	int y;
	int x;

	if (game->p1[0] >= game->p2[0])
	{
		y = -1;
		while (y++ < game->map_y)
		{
			x = game->p1[1] > game->p2[1] ? 0 : game->map_x;
			while (x != (game->p1[1] > game->p2[1] ? game->map_x : 0))
			{
				if (game->map[y][x] == 'o' || game->map[y][x] == 'O')
					return (print(x, y));
				x += game->p1[1] > game->p2[1] ? 1 : -1;
			}
		}
	}
	else if (game->p1[0] < game->p2[0])
	{
		y = game->map_y;
		while (y--)
		{
			x = game->p1[1] > game->p2[1] ? 0 : game->map_x;
			while (x != (game->p1[1] > game->p2[1] ? game->map_x : 0))
			{
				if (game->map[y][x] == 'o' || game->map[y][x] == 'O')
					return (print(x, y));
				x += game->p1[1] > game->p2[1] ? 1 : -1;
			}

		}
	}
	return (0);
}

int 	is_place(int y, int x, t_info *game)
{
	int p_y = 0;
	int p_x = 0;

	while (game->piece_y > p_y && game->map[y + p_y][x + p_x] == '.')
	{
		p_x = 0;
		while (game->piece_x > p_x && game->map[y + p_y][x + p_x] == '.')
		{
			p_x++;
			if (game->piece_y == p_y + 1 && game->piece_x == p_x + 1)
				return (1);
		}
		p_y++;
	}
	return (0);
}
