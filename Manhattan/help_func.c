#include "fillit.h"
#include "./libft/libft.h"
#include "./libft/get_next_line.h"

int 		print(int y, int x, t_info *game)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
	return (1);
}

void		players(t_info *game)
{
	char *line;

	get_next_line(0, &line);
	if (strncmp(line, "$$$ exec", 7) == 0)
	{
		game->my_num = ft_strstr(line, "p1") ? -1 : -2;
	}
	ft_strdel(&line);
	free(line);
}

int	pos(int x)
{
	return ((x < 0) ? (x * -1) : x);
}

void		free_piece(t_info *game)
{
	int y;
	
	y = 0;
	while (y < game->piece_y)
	{
		free(game->piece[y]);
		y++;
	}
	free(game->piece);
}

void		free_map(t_info *game)
{
	int y;
	
	y = 0;
	while (y < game->map_y)
	{
		free(game->map[y]);
		y++;
	}
	free(game->map);
}
