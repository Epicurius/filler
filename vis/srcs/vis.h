/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vis.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 14:47:36 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/30 16:46:54 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VIS_H
# define VIS_H

# include "SDL.h"
# include "SDL_ttf.h"
# include "libft.h"
# include "libpf.h"

# define W 1280
# define H 720
# define EMPTY 0x131313
# define PLAYER1 0x00B500
# define PLAYER2 0xFFED00
# define Y_GRAPH 350
# define X_GRAPH 500

typedef struct s_env
{
	SDL_Surface		*surface;
	SDL_Window		*win;
	SDL_Renderer	*renderer;
	SDL_Texture		*texture;
	TTF_Font		*font;
	int				pause;
	int				map_y;
	int				map_x;
	int				*map;
	int				him;
	int				me;
	int				p1;
	int				p2;
	SDL_Color		c1;
	SDL_Color		c2;
	int				max;
	int				quit;
	int				rgb;
	int				heat;
	int				moves;
	int				size;
	int				offset;
}					t_env;

void				read_input(t_env *vis);
void				mine_sweap(t_env *vis);
void				error_msg(const char *restrict format, ...);
void				square(int s_x, int s_y, t_env *vis);
void				init_map(t_env *vis);
void				title(t_env *vis);
void				score(t_env *vis);
SDL_Color			hex_to_sdl_color(int hex);
void				draw_map(t_env *vis);
void				update_screen(t_env *vis);
void				keys(t_env *vis, SDL_Event *event);
void				init_sdl(t_env *vis);

#endif
