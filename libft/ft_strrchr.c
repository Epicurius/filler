/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneronin <nneronin@stuent.hive.fi>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:22:00 by nneronin          #+#    #+#             */
/*   Updated: 2019/10/26 14:03:37 by nneronin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	*strstr;
	int		x;

	strstr = (char *)str;
	x = 0;
	while (strstr[x] != '\0')
		x++;
	if (strstr[x] == (char)c)
		return (&strstr[x]);
	while (x != 0)
	{
		x--;
		if (strstr[x] == (char)c)
			return (&strstr[x]);
	}
	return (0);
}
