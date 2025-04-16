/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_sol.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:13:15 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/16 17:47:15 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map_generator.h"

/** Fill with '+' wherever is possible to go
*	- fill -> The map
*	- size -> The size of the map
*	- y -> The y position to start filling
*	- x -> The x position to start filling
*/
void	ft_path(char **fill, t_lcn size, size_t y, size_t x)
{
	if (y >= size.y)
		return ;
	if (y >= size.y && x >= size.x)
	{
		if (fill[y][x])
			fill[y][x] = CHAR_FILL;
		return ;
	}
	if (x >= size.x || x >= ft_strlen(fill[y]))
		return ;
	if (fill[y][x] != CHAR_FLOOR)
		return ;
	if (fill[y])
		if (fill[y][x])
			fill[y][x] = CHAR_FILL;
	ft_path(fill, size, y, x + 1);
	ft_path(fill, size, y, x - 1);
	ft_path(fill, size, y - 1, x);
	ft_path(fill, size, y + 1, x);
}

int	ft_check_behind(char **map, t_lcn checkpoint, char c)
{
	if (map[checkpoint.y][checkpoint.x + 1] == c)
		return (1);
	if (map[checkpoint.y][checkpoint.x - 1] == c)
		return (1);
	if (map[checkpoint.y + 1][checkpoint.x] == c)
		return (1);
	if (map[checkpoint.y - 1][checkpoint.x] == c)
		return (1);
	return (0);
}

/* Check if player can reach all the items */
static int	ft_check_isreachabe(t_map *map)
{
	int		ok;
	size_t	size;
	size_t	len;

	size = 0;
	ok = 1;
	while (map->map[size] && ok)
	{
		len = 0;
		while (map->map[size][len] && ok == 1)
		{
			if (map->map[size][len] == CHAR_ITEM)
			{
				map->item.x = len;
				map->item.y = size;
				ok = ft_check_behind(map->sol, map->item, CHAR_FILL);
			}
			len++;
		}
		size++;
	}
	return (ok);
}

int	ft_check_for_sol(t_map *map)
{
	map->sol = ft_arrcpy(map->sol, map->map);
	map = only_floor_and_walls(map);
	ft_path(map->sol, map->size, map->player.y, map->player.x);
	if (!ft_check_behind(map->sol, map->player, CHAR_FILL))
		return (0);
	if (!ft_check_behind(map->sol, map->exit, CHAR_FILL))
		return (0);
	if (!ft_check_isreachabe(map))
		return (0);
	return (1);
}

t_map	check_map(t_map *map)
{
	map->sol = (char **)arrdup((void **)map->map);
	if (!map->sol)
		print_errmalloc();
	map = only_floor_and_walls(map);
	ft_path(map->sol, map->size, map->player.y, map->player.x);
	map = check_player(map);
	map = check_exit(map);
	map = check_items(map);
	while (!ft_check_for_sol(map))
	{
		map->path = next_path(map);
		map = open_way(map, map->path, 0);
		map->sol = ft_arrcpy(map->sol, map->map);
		map = only_floor_and_walls(map);
		ft_path(map->sol, map->size, map->path.y, map->path.x);
		ft_print_map_t(map->map);
		ft_print_map_t(map->sol);
	}
	return (*map);
}
