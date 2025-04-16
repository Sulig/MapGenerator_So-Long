/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:54:05 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/16 16:58:18 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map_generator.h"

int	main(int argc, char **args)
{
	t_map	map;

	map = init_struct_vars(&map, argc, args);
	if (!map.map)
		return (1);
	while (map.actual_map < map.num_maps)
	{
		srand(time(NULL));
		map = init_struct_vars(&map, argc, args);
		if (!map.map)
			return (1);
		generate_map(&map);
		map = check_map(&map);
		generate_file(&map);
		map.actual_map++;
		if (map.actual_map == map.num_maps)
			break ;
		free_map(&map, 0);
	}
	free_map(&map, 1);
	exit(0);
	return (0);
}
