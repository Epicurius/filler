#include "vis.h"
#include <stdio.h>
#include "../libft/libft.h"
#include "../libft/get_next_line.h"

void		players_get(char *line, t_info *game)
{
	int	x;
	char **tmp;
	char **tmp2;

	x = 0;
	tmp = ft_strsplit(line, '/');
	while (ft_strstr(tmp[x], ".filler") == 0)
	{
		ft_strdel(&tmp[x]);
		x++;
	}	
	tmp2 = ft_strsplit(tmp[x], '.');
	if (line[10] == '1')
		game->p1 = ft_strdup(tmp2[0]);
	else
		game->p2 = ft_strdup(tmp2[0]);
	ft_strdel(&tmp[x]);
	free(tmp);
	ft_strdel(&tmp2[0]);
	ft_strdel(&tmp2[1]);
	free(tmp2);
	ft_strdel(&line);
}

int	pos(int x)
{
	return ((x < 0) ? (x * -1) : x);
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
