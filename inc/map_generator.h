/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:43:52 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/16 17:12:56 by sadoming         ###   ########.fr       */
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

int		ft_check_behind(char **map, t_lcn checkpoint, char c);
t_map	*check_player(t_map *map);
t_map	*check_exit(t_map *map);
t_map	*check_items(t_map *map);
int		ft_check_for_sol(t_map *map);

/* GENERATE */
void	generate_map(t_map *map);
t_map	*open_way(t_map *map, t_lcn where, size_t random);
void	generate_file(t_map *map);

/* UTILS */
int		random_range_i(int min, int max);
size_t	random_range_u(size_t min, size_t max);

void	ft_print_stat(t_map *map);
void	ft_print_map_t(char **map);

t_map	*close_map(t_map *map);
t_map	*only_floor_and_walls(t_map *map);
void	ft_path(char **fill, t_lcn size, size_t y, size_t x);
t_lcn	next_item(t_map *map);
t_lcn	next_path(t_map *map);

#endif
