/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utilities.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:13:15 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/16 17:35:33 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map_generator.h"

/* Return ubication of next item*/
t_lcn	next_item(t_map *map)
{
	t_lcn	item;

	if (map->item.y && map->item.x)
	{
		item.x = map->item.x;
		item.y = map->item.y;
	}
	else
	{
		item.x = 0;
		item.y = 0;
	}
	while (item.y < map->height)
	{
		while (item.x < ft_strlen(map->map[item.y]))
		{
			if (map->map[item.y][item.x] == CHAR_ITEM)
				return (item);
			item.x++;
		}
		item.x = 0;
		item.y++;
	}
	return (item);
}

static int	check_behind(char **map, t_lcn checkpoint, char c)
{
	int okk;

	okk = 0;
	if (map[checkpoint.y][checkpoint.x + 1] == c)
		okk += 1;
	if (map[checkpoint.y][checkpoint.x - 1] == c)
		okk += 1;
	if (map[checkpoint.y + 1][checkpoint.x] == c)
		okk += 1;
	if (map[checkpoint.y - 1][checkpoint.x] == c)
		okk += 1;
	return (okk);
}

t_lcn	next_path(t_map *map)
{
	t_lcn	path;

	if (map->path.y && map->path.x)
	{
		path.x = map->start.x;
		path.y = map->start.y;
	}
	else
	{
		path.x = 0;
		path.y = 0;
	}
	while (path.y < map->height)
	{
		while (path.x < ft_strlen(map->sol[path.y]))
		{
			if (map->sol[path.y][path.x] == CHAR_FILL)
				if (check_behind(map->sol, path, CHAR_WALL) >= 3)
					return (path);
			path.x++;
		}
		path.x = 0;
		path.y++;
	}
	return (path);
}

/* Map the sol map with only walls and floor */
t_map	*only_floor_and_walls(t_map *map)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (i < map->height)
	{
		j = 0;
		while (j < ft_strlen(map->map[i]))
		{
			if (map->sol[i][j] != CHAR_WALL)
				map->sol[i][j] = CHAR_FLOOR;
			j++;
		}
		i++;
	}
	return (map);
}

