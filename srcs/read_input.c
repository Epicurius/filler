/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 09:36:44 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/07 15:58:07 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./filler.h"

void	map_size(char *line, t_info *game)
{
	int i;
	int y;

	i = 8;
	y = ft_atoi(&line[i]);
	if (y == game->map_y)
		return ;
	game->map_y = y;
	while (line[i] != ' ')
		i++;
	i += 1;
	game->map_x = ft_atoi(&line[i]);
	game->map = (int **)malloc(sizeof(int *) * game->map_y);
}

void	map_malloc(char *line, t_info *game)
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
		if (ft_strlen(line) != (game->map_x + 4))
			exit(1);
		if (game->override == 0)
			game->map[y] = (int *)malloc(sizeof(int) * game->map_x);
		while (x++ <= (game->map_x - 1))
		{
			if (line[x + 4] == '.')
				game->map[y][x] = 0;
			else if (line[x + 4] == 'o' || line[x + 4] == 'O')
				game->map[y][x] = -1;
			else if (line[x + 4] == 'x' || line[x + 4] == 'X')
				game->map[y][x] = -2;
		}
		ft_strdel(&line);
	}
}

void	piece_size(char *line, t_info *game)
{
	int i;

	i = 6;
	game->piece_y = 0;
	game->piece_x = 0;
	game->piece_y = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	i += 1;
	game->piece_x = ft_atoi(&line[i]);
	game->piece = (int **)malloc(sizeof(int *) * game->piece_y);
}

void	piece_malloc(char *line, t_info *game)
{
	int y;
	int x;

	y = -1;
	while (++y <= (game->piece_y - 1))
	{
		x = -1;
		get_next_line(0, &line);
		if (ft_strlen(line) != game->piece_x)
			exit(1);
		game->piece[y] = (int *)malloc(sizeof(int) * game->piece_x);
		while (x++ <= (game->piece_x - 1))
		{
			if (line[x] == '.')
				game->piece[y][x] = 0;
			else if (line[x] == '*')
				game->piece[y][x] = 1;
		}
		ft_strdel(&line);
	}
}

int	read_input(t_info *game)
{
	char *line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			map_size(line, game);
			ft_strdel(&line);
			map_malloc(line, game);
		}
		else if (ft_strncmp(line, "Piece", 4) == 0)
		{
			piece_size(line, game);
			ft_strdel(&line);
			piece_malloc(line, game);
			free(line);
			return (1);
		}
		else
			ft_strdel(&line);
	}
	ft_strdel(&line);
	free(line);
	return (0);
}
