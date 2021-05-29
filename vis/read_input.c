/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:36:44 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/29 14:32:20 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void		map_size(char *line, t_info *game)
{
	int i;
	int y;

	i = 8;
	y = ft_atoi(&line[i]);
	game->map_y = y;
	while (line[i] != ' ')
		i++;
	i += 1;
	game->map_x = ft_atoi(&line[i]);
	game->map = (int **)malloc(sizeof(int *) * game->map_y);
}

void		map_malloc(char *line, t_info *game)
{
	int y;
	int x;

	y = -1;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (++y <= (game->map_y - 1))
	{
		x = -1;
		get_next_line(0, &line);
		if (game->not_malloc == 0)
			game->map[y] = (int *)malloc(sizeof(int) * game->map_x);
		while (x++ <= (game->map_x - 1))
		{
			if (line[x + 4] == '.')
				game->map[y][x] = 0;
			else if (line[x + 4] == 'O' || line[x + 4] == 'o')
				game->map[y][x] = line[x + 4] == 'O' ? -1 : -3;
			else if (line[x + 4] == 'X' || line[x + 4] == 'x')
				game->map[y][x] = line[x + 4] == 'X' ? -2 : -4;
		}
		ft_strdel(&line);
	}
	if (game->not_malloc == 0)
		game->not_malloc = 1;
}

int			read_input(t_info *game)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "$$$", 2) == 0)
			players_get(line, game);
		else if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			if (game->not_malloc == 0)
				map_size(line, game);
			ft_strdel(&line);
			map_malloc(line, game);
		}
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			ft_strdel(&line);
			free(line);
			return (1);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}
