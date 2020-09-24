/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:18:32 by nneronin          #+#    #+#             */
/*   Updated: 2020/06/02 07:20:57 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIS_H
# define VIS_H

# include "../libft/libft.h"
# include "./mlx/mlx.h"
# define WIDTH 1200
# define HEIGHT 600
# define EMPTY 0x131313
# define PLAYER1 0x00B500
# define PLAYER2 0xFFED00
# define Y_GRAPH 75
# define X_GRAPH 90

typedef struct		s_info
{
	int				graph[75][90];
	char			*p1;
	char			*p2;
	int				s1;
	int				s2;
	int				max;
	int				heat;
	int				pause;
	int				not_malloc;
	int				map_y;
	int				map_x;
	int				**map;
	char			*pic;
	void			*mlx;
	void			*win;
	void			*img;
	int				rgb;
	int				endian;
	int				bits_per_pixel;
	int				size_line;
}					t_info;

void				background(t_info *game);
void				draw_map(t_info *game);
int					key_press(int code, t_info *game);
int					read_input(t_info *game);
int					draw(t_info *game);
int					heat_color(int value, t_info *game);
void				players_get(char *line, t_info *game);
int					pos(int x);
void				free_piece(t_info *game);
void				free_map(t_info *game);
int					mine_sweap(t_info *game, int y, int x);
int					graph(int s, int total, int p, t_info *game);
int					graph_initiate(t_info *game);

#endif
