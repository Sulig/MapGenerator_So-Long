/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:43:52 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/14 19:49:09 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_GENERATOR_H
# define MAP_GENERATOR_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <time.h>

# include "../New_Libft/inc/libft.h"
# include "map_const.h"
# include "gen_structs.h"

/* PRINTING ERRORS */
void	print_errmalloc(void);
void	print_custom_err(char *err);

/* MAP */
t_map	*free_map(t_map *map, int all);
t_map	init_struct_vars(t_map *map, int argc, char **args);
t_map	check_map(t_map *map);

/* GENERATE */
void	generate_map(t_map *map);

/* UTILS */
int		random_range_i(int min, int max);
size_t	random_range_u(size_t min, size_t max);

void	ft_print_stat(t_map *map);
void	ft_print_map_t(char **map);

#endif
