/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:18:32 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/29 14:28:47 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include "libpf.h"

typedef struct s_info
{
	int				*map;
	int				map_y;
	int				map_x;
	int				*piece;
	int				piece_y;
	int				piece_x;
	int				piece_area;
	int				final_x;
	int				final_y;
	int				value;
	int				me;
	int				him;
}					t_info;

void			error_msg(const char *restrict format, ...);
void			players(t_info *game);
int				pos(int x);
void			read_input(t_info *game);
void			surround(t_info *game);
void			mine_sweap(t_info *game);

#endif
