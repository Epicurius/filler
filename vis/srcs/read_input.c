/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:55:04 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/30 11:50:55 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

void	init_map(t_env *vis)
{
	int	y;
	int	x;

	vis->rgb = EMPTY;
	y = -1;
	while (++y < vis->map_y)
	{
		x = -1;
		while (++x < vis->map_x)
			square((x * vis->size) + (x * 2) + 2,
				(y * vis->size) + (y * 2) + vis->offset, vis);
	}
}

static void	map_size(char *line, t_env *vis)
{
	int	i;

	i = 8;
	vis->map_x = -1;
	vis->map_y = -1;
	vis->map_y = ft_atoi(&line[i]);
	while (line[i] != ' ')
		i++;
	i += 1;
	vis->map_x = ft_atoi(&line[i]);
	vis->map = ft_memalloc(sizeof(int) * (vis->map_y * vis->map_x));
	vis->size = ((W / 2) / (vis->map_x)) - 2;
	vis->offset = ((H - (vis->map_y * vis->size) - (vis->map_y * 2)) / 2);
	init_map(vis);
}

static void	read_map(char *line, t_env *vis)
{
	int	y;
	int	x;

	y = -1;
	get_next_line(0, &line);
	ft_strdel(&line);
	while (++y < vis->map_y)
	{
		x = -1;
		get_next_line(0, &line);
		while (++x < vis->map_x)
		{
			if (line[x + 4] == '.')
				vis->map[y * vis->map_x + x] = 0;
			else if (line[x + 4] == 'o')
				vis->map[y * vis->map_x + x] = -3;
			else if (line[x + 4] == 'O')
				vis->map[y * vis->map_x + x] = -1;
			else if (line[x + 4] == 'x')
				vis->map[y * vis->map_x + x] = -4;
			else if (line[x + 4] == 'X')
				vis->map[y * vis->map_x + x] = -2;
		}
		ft_strdel(&line);
	}
}

void	players_get(char *line, t_env *vis)
{
	int			nb;
	char		**arr;
	char		*str;
	SDL_Surface	*tmp;
	SDL_Rect	dstr;

	arr = ft_strsplit(line, '/', &nb);
	str = ft_strndup(arr[nb - 1], ft_strlen(arr[nb - 1]) - 8);
	if (line[10] == '1')
	{
		tmp = TTF_RenderText_Blended(vis->font, str, vis->c1);
		dstr = (SDL_Rect){W / 2 + 125, H / 3.5, tmp->w, tmp->h};
		SDL_BlitSurface(tmp, NULL, vis->surface, &dstr);
	}
	else
	{
		tmp = TTF_RenderText_Blended(vis->font, str, vis->c2);
		dstr = (SDL_Rect){W / 2 + 400, H / 3.5, tmp->w, tmp->h};
		SDL_BlitSurface(tmp, NULL, vis->surface, &dstr);
	}
	SDL_FreeSurface(tmp);
	free(str);
	free(arr);
	ft_strdel(&line);
}

void	read_input(t_env *vis)
{
	char	*line;

	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		if (ft_strnequ(line, "$$$", 2))
			players_get(line, vis);
		else if (ft_strnequ(line, "Plateau", 6))
		{
			if (!vis->map)
				map_size(line, vis);
			ft_strdel(&line);
			read_map(line, vis);
		}
		else if (ft_strnequ(line, "Piece", 4))
			break ;
		else
			ft_strdel(&line);
	}
	ft_strdel(&line);
	free(line);
}
