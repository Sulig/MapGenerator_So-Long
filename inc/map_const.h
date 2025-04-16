/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_const.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:16:33 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/16 17:09:05 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_CONST_H
# define MAP_CONST_H

# define MAX_INT	2147483647	// Max int value

# define MAP_NAME_FILE	"Generated_Map_"	// Default map name
# define MAP_NAME_EXT	".ber"				// Default map extension

# define MAX_MAP_WIDTH	20	// Max map width
# define MAX_MAP_HEIGHT	20	// Max map height

# define MAP_WIDTH		0
# define MAP_HEIGHT		0

# define NUM_OF_ITEMS	0	// Number of items
# define NUM_OF_ENEMIES	0	// Number of enemies

# define MAP_CHARS		"01PEC"	// Map characters
# define CHAR_WALL		'1'	// Wall character
# define CHAR_FLOOR		'0'	// Space character
# define CHAR_PLAYER	'P'	// Player character
# define CHAR_EXIT		'E'	// Exit character
# define CHAR_ITEM		'C'	// Item character
# define CHAR_ENEMY		'\0'	// Enemy character

# define CHAR_FILL		'+'	// Fill character

/*		 ## ERRORS CONSTS ##		*/
# define MALLOC_ERROR	"Insuficient Memory or Malloc Error\n"
# define BAD_FILE		"Error\nThis file don't exist!\n"
/*	## ERRORS CONSTS END ##	*/

#endif
