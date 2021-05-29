/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 12:25:13 by nneronin          #+#    #+#             */
/*   Updated: 2021/05/29 14:19:14 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	error_msg(const char *restrict format, ...)
{
	t_pf	p;
	char	buff[PF_BUFF_SIZE];

	write(1, "\x1b[31m[ERROR]\x1b[00m", 17);
	if (format)
	{
		write(1, "\t", 1);
		pf_init(&p, 1);
		p.buffer = buff;
		va_start(p.ap, format);
		pf_read_format((char *)format, &p);
		write(p.fd, p.buffer, p.chars);
		va_end(p.ap);
	}
	else
		write(1, "\n", 1);
	exit(1);
}

void	players(t_info *game)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strnequ(line, "$$$ exec ", 8))
	{
		if (ft_strstr(line, "p1"))
			game->me = -1;
		else if (ft_strstr(line, "p2"))
			game->me = -2;
		else
			error_msg("No player number!");
	}
	else
		error_msg("Player format!");
	game->him = -1;
	if (game->me == -1)
		game->him = -2;
	ft_strdel(&line);
	free(line);
}

int	pos(int x)
{
	if (x < 0)
		return (x * -1);
	return (x);
}
