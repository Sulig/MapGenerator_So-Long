/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:13:15 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/14 20:22:22 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map_generator.h"

static void	path(char **fill, t_lcn size, size_t y, size_t x)
{
	if (y == size.y && x == size.x)
	{
		if (fill[y][x])
			fill[y][x] = '+';
		return ;
	}
	if (fill[y][x] != CHAR_FLOOR)
		return ;
	if (fill[y][x])
		fill[y][x] = '+';
	path(fill, size, y, x + 1);
	path(fill, size, y, x - 1);
	path(fill, size, y - 1, x);
	path(fill, size, y + 1, x);
}

static	int	check_behind(char **map, t_lcn checkpoint)
{
	if (map[checkpoint.y][checkpoint.x + 1] == '+')
		return (1);
	if (map[checkpoint.y][checkpoint.x - 1] == '+')
		return (1);
	if (map[checkpoint.y + 1][checkpoint.x] == '+')
		return (1);
	if (map[checkpoint.y - 1][checkpoint.x] == '+')
		return (1);
	return (0);
}

int	check_for_sol(t_map *map)
{
	int		ok;
	size_t	size;
	size_t	len;
	t_lcn	coin;

	path(map->sol, map->exit, map->start.y, map->start.x);
	ok = check_behind(map->sol, map->exit);
	size = 0;
	while (map->map[size] && ok)
	{
		len = 0;
		while (map->map[size][len] && ok == 1)
		{
			if (map->map[size][len] == CHAR_ITEM)
			{
				coin.x = len;
				coin.y = size;
				ok = check_behind(map->sol, coin);
			}
			len++;
		}
		size++;
	}
	return (ok);
}

t_map	check_map(t_map *map)
{
	map->sol = (char **)arrdup((void **)map->map);
	if (!map->sol)
		print_errmalloc();
	check_for_sol(map);
	ft_print_stat(map);
	ft_print_map_t(map->sol);
	return (*map);
}
