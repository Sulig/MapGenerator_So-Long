/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_vars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:04:16 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/16 15:10:06 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map_generator.h"

/* Generate the map size */
static t_map	*generate_map_size(t_map *map)
{
	if ((MAP_WIDTH < 3 && MAP_HEIGHT < 5) || (MAP_WIDTH < 5 && MAP_HEIGHT < 3))
	{
		if (MAX_MAP_WIDTH < 3 && MAX_MAP_HEIGHT < 5)
		{
			map->width = random_range_u(7, MAX_INT);
			map->height = random_range_u(7, MAX_INT);
		}
		else if (MAX_MAP_WIDTH < 5 && MAX_MAP_HEIGHT < 3)
		{
			map->width = random_range_u(7, MAX_INT);
			map->height = random_range_u(7, MAX_INT);
		}
		else
		{
			map->width = random_range_u(5, MAX_MAP_WIDTH);
			map->height = random_range_u(3, MAX_MAP_HEIGHT);
		}
	}
	else
	{
		map->width = MAP_WIDTH;
		map->height = MAP_HEIGHT;
	}
	return (map);
}

/* Calculate how many free cells will be
** Considering the map surrounded by walls
** and the number of enemies and items
*** * free_cells - 2 (Reserve space for the player and the exit)
*/
static t_map	*calculate_free_cells(t_map *map)
{
	size_t	size;
	size_t	len;

	size = (map->width * 2) - 2;
	len = (map->height * 2) - 2;
	map->free_cells = size + len - 2;
	map->free_cells -= map->enemies;
	map->free_cells -= map->items;
	return (map);
}

/* Initialize the map variables */
static t_map	*init_map(t_map *map)
{
	if (MAP_WIDTH > 0)
		map->width = MAP_WIDTH;
	if (MAP_HEIGHT > 0)
		map->height = MAP_HEIGHT;
	map = generate_map_size(map);
	if (NUM_OF_ENEMIES > 0)
		map->enemies = NUM_OF_ENEMIES;
	map = calculate_free_cells(map);
	if (NUM_OF_ITEMS > 0)
		map->items = NUM_OF_ITEMS;
	else
		map->items = random_range_u(1, map->free_cells);
	map->map = ft_arr_strcreate(map->height, map->width);
	if (!map->map)
		print_errmalloc();
	map->size.y = map->height;
	map->size.x = map->width;
	return (map);
}

/* Free the map */
t_map	*free_map(t_map *map, int all)
{
	map->map = ft_free_arrstr(map->map);
	map->sol = ft_free_arrstr(map->sol);
	if (all)
	{
		ft_bzero(map, sizeof(t_map));
		return (NULL);
	}
	return (map);
}

/* Initialize the struct variables */
t_map	init_struct_vars(t_map *map, int argc, char **args)
{
	ft_bzero(map, sizeof(t_map));
	if (argc > 2 && args[1])
	{
		if (ft_isdigit_all(args[1]))
			map->num_maps = ft_atos(args[1]);
		else
			map->directory = args[1];
	}
	if (argc > 3 && args[2])
	{
		if (ft_isdigit_all(args[2]) && !map->num_maps)
			map->num_maps = ft_atos(args[2]);
		else
			map->directory = args[2];
	}
	if (map->num_maps < 1)
		map->num_maps = 1;
	if (!map->directory)
		map->directory = "./";
	map = init_map(map);
	return (*map);
}
