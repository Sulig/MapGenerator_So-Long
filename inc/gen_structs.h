/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gen_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:38:43 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/31 20:12:27 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GEN_STRUCTS_H
# define GEN_STRUCTS_H

# include "stdlib.h"

/* LOCATION STRUCT */
/*
	- x -> X Position
	- y -> Y Position
*/
typedef struct s_lcn
{
	size_t	x;
	size_t	y;
}			t_lcn;

/* MAP STRUCT */
/*
	- map -> Map
	- sol -> Solution
	- height -> Map Height
	- width -> Map Width
	- player -> Player Count
	- exits -> Exit Count
	- items -> Item Count
	- enemies -> Enemy Count
	- start -> Start Location
	- exit -> Exit Location
	- directory -> Directory
	- num_maps -> Number of Maps
*/
typedef struct	s_map
{
	char		**map;
	char		**sol;
	size_t		height;
	size_t		width;
	size_t		free_cells;
	size_t		player;
	size_t		exits;
	size_t		items;
	size_t		enemies;
	t_lcn		start;
	t_lcn		exit;
	char		*directory;
	size_t		num_maps;
	size_t		actual_map;
}				t_map;

#endif
