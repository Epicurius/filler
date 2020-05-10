
#include "filler.h"

int		main(void)
{
	t_info		*game;

	game = (t_info *)malloc(sizeof(*game));
	game->override = 0;
	game->map_x = -1;
	game->map_y = -1;
	players(game);
	while (1)
	{
		read_input(game);
		game->override = 1;
		game->value = 2147483647;
		mine_sweap(game);
		surround(game);
		if (game->value == 2147483647)
			break ;
		print(game->fin[0], game->fin[1], game);
		free_piece(game);
	}
	free_piece(game);
	free_map(game);
	return (0);
}
