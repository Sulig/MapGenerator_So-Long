/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator_main.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:54:05 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/31 20:14:31 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/map_generator.h"

int	main(int argc, char **args)
{
	t_map	map;

	map = init_map(&map, argc, args);
	if (!map.map)
		return (1);
	if (map.num_maps > 1)
	{
		while (map.actual_map < map.num_maps)
		{
			free_map(&map);
			map = init_map(&map, argc, args);
			if (!map.map)
				return (1);
			//map = generate_map(map);
		}
	}
	exit(0);
	return (0);
}
