/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:25:57 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/30 12:02:34 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int	main(void)
{
	t_info		*game;

	game = (t_info *)malloc(sizeof(*game));
	if (!game)
		error_msg("Malloc game.");
	game->map = NULL;
	game->piece = NULL;
	players(game);
	while (1)
	{
		read_input(game);
		mine_sweap(game);
		surround(game);
		if (game->value == 2147483647)
			break ;
		ft_printf("%d %d\n", game->final_y, game->final_x);
		free(game->piece);
		game->piece = NULL;
	}
	if (game->piece)
		free(game->piece);
	if (game->map)
		free(game->map);
	free(game);
	return (0);
}
