/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:43:52 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/31 20:11:14 by sadoming         ###   ########.fr       */
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
t_map	*free_map(t_map *map);
t_map	init_map(t_map *map, int argc, char **args);

/* UTILS */
int		randomRange_i(int min, int max);
size_t	randomRange_u(size_t min, size_t max);

#endif
