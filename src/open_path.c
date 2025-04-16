/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:13:15 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/16 17:19:01 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map_generator.h"

t_map	*open_way(t_map *map, t_lcn where, size_t random)
{
	if (random == 1 && map->map[where.y][where.x + 1] == CHAR_WALL)
		map->map[where.y][where.x + 1] = CHAR_FLOOR;
	else if (random == 2 && map->map[where.y][where.x - 1] == CHAR_WALL)
		map->map[where.y][where.x - 1] = CHAR_FLOOR;
	else if (random == 3 && map->map[where.y + 1][where.x] == CHAR_WALL)
		map->map[where.y + 1][where.x] = CHAR_FLOOR;
	else if (random == 4 && map->map[where.y - 1][where.x] == CHAR_WALL)
		map->map[where.y - 1][where.x] = CHAR_FLOOR;
	else
	{
		if (!ft_check_for_sol(map))
		{
			random = random_range_u(1, 4);
			where = next_path(map);
			return (open_way(map, where, random));
		}
		else
			return (close_map(map));
	}
	return (close_map(map));
}

t_map	*check_player(t_map *map)
{
	while (!ft_check_behind(map->sol, map->player, CHAR_FILL))
	{
		map = open_way(map, map->player, 0);
		map->sol = ft_arrcpy(map->sol, map->map);
		map = only_floor_and_walls(map);
		ft_path(map->sol, map->size, map->player.y, map->player.x);
	}
	return (map);
}

t_map	*check_exit(t_map *map)
{
	ft_path(map->sol, map->size, map->exit.y, map->exit.x);
	while (!ft_check_behind(map->sol, map->exit, CHAR_FILL))
	{
		map = open_way(map, map->exit, 0);
		map->sol = ft_arrcpy(map->sol, map->map);
		map = only_floor_and_walls(map);
		ft_path(map->sol, map->size, map->exit.y, map->exit.x);
	}
	return (map);
}

t_map	*check_items(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->items)
	{
		map->item = next_item(map);
		ft_path(map->sol, map->size, map->item.y, map->item.x);
		while (!ft_check_behind(map->sol, map->item, CHAR_FILL))
		{
			map = open_way(map, map->item, 0);
			map->sol = ft_arrcpy(map->sol, map->map);
			map = only_floor_and_walls(map);
			ft_path(map->sol, map->size, map->item.y, map->item.x);
		}
		i++;
	}
	return (map);
}
