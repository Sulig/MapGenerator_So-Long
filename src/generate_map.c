/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:24:08 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/14 19:49:16 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map_generator.h"

/* Close the map with walls */
t_map	*close_map(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		map->map[i][0] = CHAR_WALL;
		map->map[i][map->width - 1] = CHAR_WALL;
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		map->map[0][i] = CHAR_WALL;
		map->map[map->height - 1][i] = CHAR_WALL;
		i++;
	}
	return (map);
}

/* Locate the player and the exit in a random place inside the map */
t_map	*locate_player_and_exit(t_map *map)
{
	map->player.x = random_range_u(1, map->width - 2);
	map->player.y = random_range_u(1, map->height - 2);
	map->exit.x = random_range_u(1, map->width - 2);
	map->exit.y = random_range_u(1, map->height - 2);
	while (map->exit.x == map->player.x && map->exit.y == map->player.y)
	{
		map->exit.x = random_range_u(1, map->width - 2);
		map->exit.y = random_range_u(1, map->height - 2);
	}
	map->map[map->player.y][map->player.x] = CHAR_PLAYER;
	map->map[map->exit.y][map->exit.x] = CHAR_EXIT;
	return (map);
}

/* Ubicate all the items in the map */
t_map	*locate_items(t_map *map)
{
	size_t	i;
	t_lcn	item;

	i = 0;
	while (i < map->items)
	{
		item.x = random_range_u(1, map->width - 2);
		item.y = random_range_u(1, map->height - 2);
		while (map->map[item.y][item.x])
		{
			item.x = random_range_u(1, map->width - 2);
			item.y = random_range_u(1, map->height - 2);
		}
		map->map[item.y][item.x] = CHAR_ITEM;
		i++;
	}
	return (map);
}

/* Ubicate all the enemies (if defined) */
t_map	*locate_enemies(t_map *map)
{
	size_t	i;
	t_lcn	enemy;

	i = 0;
	while (i < map->enemies)
	{
		enemy.x = random_range_u(1, map->width - 2);
		enemy.y = random_range_u(1, map->height - 2);
		while (map->map[enemy.y][enemy.x])
		{
			enemy.x = random_range_u(1, map->width - 2);
			enemy.y = random_range_u(1, map->height - 2);
		}
		map->map[enemy.y][enemy.x] = CHAR_ENEMY;
		i++;
	}
	return (map);
}

void	generate_map(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	map = close_map(map);
	map = locate_player_and_exit(map);
	map = locate_items(map);
	map = locate_enemies(map);
	while (i < map->height)
	{
		j = 0;
		while (j < map->width)
		{
			if (!map->map[i][j])
			{
				if (random_range_i(0, 1) == 0)
					map->map[i][j] = CHAR_FLOOR;
				else
					map->map[i][j] = CHAR_WALL;
			}
			j++;
		}
		i++;
	}
}
