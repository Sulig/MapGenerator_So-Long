/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map_t.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 18:59:29 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/14 20:10:20 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map_generator.h"

void	ft_print_stat(t_map *map)
{
	ft_printf(WR);
	ft_printf("Width of map: %u\n", map->width);
	ft_printf("Height of map: %u\n\n", map->height);
	ft_printf("Num of collectables: %u\n", map->items);
	ft_printf("Player are in [%u][%u]\n", map->player.y, map->player.x);
	ft_printf("Exit are in [%u][%u]\n", map->exit.y, map->exit.x);
	if (map->map)
	{
		ft_printf("\nPreview of map:\n\n");
		ft_print_map_t(map->map);
	}
}

static void	print_t_case(char c)
{
	if (c == CHAR_WALL)
		ft_printf(CR);
	else if (c == CHAR_FLOOR)
		ft_printf(B);
	else if (c == CHAR_ITEM)
		ft_printf(YR);
	else if (c == CHAR_PLAYER)
		ft_printf(WR);
	else if (c == CHAR_EXIT)
		ft_printf(GR);
	else if (c == CHAR_ENEMY)
		ft_printf(PR);
	else
		ft_printf(RR);
	ft_printf("%c", c);
}

void	ft_print_map_t(char **map)
{
	size_t	size;
	size_t	len;

	size = 0;
	while (map[size])
	{
		len = 0;
		while (map[size][len])
		{
			print_t_case(map[size][len]);
			len++;
		}
		size++;
		ft_printf("\n");
	}
	ft_printf("\n");
}
