/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:36:44 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/29 18:28:08 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void	map_size(char *line, t_info *game)
{
	int	i;

	i = 8;
	game->map_x = -1;
	game->map_y = -1;
	game->map_y = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	i += 1;
	game->map_x = ft_atoi(&line[i]);
	game->map = ft_memalloc(sizeof(int) * (game->map_y * game->map_x));
}

static void	read_map(char *line, t_info *game)
{
	int	y;
	int	x;

	y = -1;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (++y < game->map_y)
	{
		x = -1;
		get_next_line(0, &line);
		while (++x < game->map_x)
		{
			if (line[x + 4] == '.')
				game->map[y * game->map_x + x] = 0;
			else if (line[x + 4] == 'o' || line[x + 4] == 'O')
				game->map[y * game->map_x + x] = -1;
			else if (line[x + 4] == 'x' || line[x + 4] == 'X')
				game->map[y * game->map_x + x] = -2;
		}
		ft_strdel(&line);
	}
}

static void	piece_size(char *line, t_info *game)
{
	int	i;

	i = 6;
	game->piece_y = 0;
	game->piece_x = 0;
	game->piece_area = 0;
	game->piece_y = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	i += 1;
	game->piece_x = ft_atoi(&line[i]);
	game->piece = ft_memalloc(sizeof(int) * (game->piece_y * game->piece_x));
}

static void	piece_malloc(char *line, t_info *game)
{
	int	y;
	int	x;

	y = -1;
	while (++y < game->piece_y)
	{
		x = -1;
		get_next_line(0, &line);
		while (++x < game->piece_x)
		{
			if (line[x] != '*')
				continue ;
			game->piece[y * game->piece_x + x] = 1;
			game->piece_area += 1;
		}
		ft_strdel(&line);
	}
}

void	read_input(t_info *game)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strnequ(line, "Plateau", 6))
		{
			if (!game->map)
				map_size(line, game);
			ft_strdel(&line);
			read_map(line, game);
		}
		else if (ft_strnequ(line, "Piece", 4))
		{
			piece_size(line, game);
			ft_strdel(&line);
			piece_malloc(line, game);
			break ;
		}
		else
			ft_strdel(&line);
	}
	ft_strdel(&line);
	free(line);
}
