
#include "vis.h"
#include "../libft/get_next_line.h"

int		main(void)
{
	t_info		*game;

	game = (t_info *)malloc(sizeof(*game));
	graph_initiate(game);
	game->map_x = -1;
	game->map_y = -1;
	game->heat = 0;
	game->pause = 0;
	game->not_malloc = 0;
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, WIDTH, HEIGHT, "Game");
	game->img = mlx_new_image(game->mlx, WIDTH, HEIGHT);
	mlx_hook(game->win, 2, 2, key_press, game);
	draw(game);
	game->pause = 1;
	mlx_loop_hook(game->mlx, draw, game);
	mlx_loop(game->mlx);
	free_map(game);
	return (0);
}