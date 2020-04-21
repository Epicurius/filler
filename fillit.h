/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/13 16:18:32 by nneronin          #+#    #+#             */
/*   Updated: 2020/03/07 11:35:47 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "./libft/libft.h"

typedef struct		s_info
{
	int		map_y;
	int		map_x;
	int		piece_y;
	int		piece_x;
	int		p1[2];
	int		p2[2];
	int		num;
	char		**map;
	char		**piece;
}			t_info;

#endif
