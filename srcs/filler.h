/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:18:32 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/07 11:35:47 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"

typedef struct		s_info
{
	int		map_y;
	int		map_x;
	int		piece_y;
	int		piece_x;
	int		fin[2];
	int		override;
	int		**map;
	int		value;
	int		my_num;
	int		**piece;
}			t_info;


int 		print(int y, int x, t_info *game);
void		players(t_info *game);
int		pos(int x);
void		free_piece(t_info *game);
void		free_map(t_info *game);

int		mine_sweap(t_info *game);
int		proximity_calc(int y, int x, t_info *game);
int		surround(t_info *game);
//int 		is_space(int y, int x, t_info *game);
int		read_input(t_info *game);

#endif
