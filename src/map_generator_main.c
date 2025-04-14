/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:54:05 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/14 19:48:46 by sadoming         ###   ########.fr       */
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
		generate_map(&map);
		map = check_map(&map);
		map.actual_map = map.num_maps; //
		free_map(&map, 0);
		map = init_struct_vars(&map, argc, args);
		if (!map.map)
			return (1);
	}
	free_map(&map, 1);
	exit(0);
	return (0);
}
