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

#include <stdio.h>
#include "fillit.h"
#include "./libft/libft.h"
#include "./libft/get_next_line.h"

void		map_size(char *line, t_info *game)
{
	int i;

	i = 8;
	game->map_y += ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	i += 1;
	game->map_x += ft_atoi(&line[i]);
	game->map = (char **)malloc(sizeof(char *) * (game->map_y + 1));
}

void		map_malloc(char *line, t_info *game)
{
	int	i;

	i = -1;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (++i <= (game->map_y - 1))
	{
		get_next_line(0, &line);
		game->map[i] = ft_strdup(&line[4]);
		ft_strdel(&line);
	}
}

void		piece_size(char *line, t_info *game)
{
	int i;

	i = 6;
	game->piece_y += ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	i += 1;
	game->piece_x += ft_atoi(&line[i]);
	game->piece = (char **)malloc(sizeof(char *) * game->piece_y);
	i = -1;
	ft_strdel(&line);
	while (++i < game->piece_y)
	{
		get_next_line(0, &line);
		game->piece[i] = ft_strdup(line);
		ft_strdel(&line);
	}
}

int		main(void)
{
	t_info		*game;
	char		*line;
	
	game = (t_info *)malloc(sizeof(*game));
	line = NULL;
	while (1)
	{
		game->map_y = 0;
		game->map_x = 0;
		game->num = 1;
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
				printf("%d %d\n", game->piece_y, game->piece_x);
				return (0);
			}
			else
				ft_strdel(&line);
		}
	}
	return (0);
}
