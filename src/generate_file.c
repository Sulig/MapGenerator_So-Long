/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generate_file.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/02 17:13:15 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/16 16:57:38 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map_generator.h"

static void	write_map(t_map *map, int fd)
{
	size_t	i;

	i = 0;
	while (i < map->height)
	{
		ft_printf_fd(fd, "%s\n", map->map[i]);
		i++;
	}
}

void	generate_file(t_map *map)
{
	int		fd;
	char	*filename;

	filename = ft_strjoin(map->directory, MAP_NAME_FILE);
	filename = ft_strjoin_free_fst(filename, ft_itoa_unsig(map->actual_map, BASE_10));
	filename = ft_strjoin_free_fst(filename, MAP_NAME_EXT);
	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd < 0)
		print_custom_err("Error\nCan't create the file!\n");
	else
	{
		write_map(map, fd);
		close(fd);
		ft_printf(GR);
		ft_printf("The map has been generated successfully!\n");
		ft_printf("\nFile name as: %s\n\n", filename);
		ft_print_stat(map);
		ft_printf(D);
	}
	filename = ft_free_str(filename);
}
