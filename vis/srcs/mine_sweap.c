/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mine_sweap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/29 15:00:15 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/30 11:45:31 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vis.h"

int	pos(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}

static int	proximity_calc(int map_x, int map_y, t_env *vis)
{
	int	x;
	int	y;
	int	value;
	int	min_value;

	y = -1;
	min_value = 2147483647;
	while (++y < vis->map_y)
	{
		x = -1;
		while (++x < vis->map_x)
		{
			if (vis->map[y * vis->map_x + x] == -1)
			{
				value = pos(y - map_y) + pos(x - map_x);
				if (value < min_value)
				{
					if (value <= 1)
						return (value);
					min_value = value;
				}
			}
		}
	}
	return (min_value);
}

void	mine_sweap(t_env *vis)
{
	int	y;
	int	x;

	vis->p1 = 0;
	vis->p2 = 0;
	vis->max = 0;
	y = -1;
	while (++y < vis->map_y)
	{
		x = -1;
		while (++x < vis->map_x)
		{
			if (vis->map[y * vis->map_x + x] == 0)
				vis->map[y * vis->map_x + x] = proximity_calc(x, y, vis);
			else if (vis->map[y * vis->map_x + x] == -1
				|| vis->map[y * vis->map_x + x] == -3)
				vis->p1 += 1;
			else if (vis->map[y * vis->map_x + x] == -2
				|| vis->map[y * vis->map_x + x] == -4)
				vis->p2 += 1;
			if (vis->map[y * vis->map_x + x] > vis->max)
				vis->max = vis->map[y * vis->map_x + x];
		}
	}
}
