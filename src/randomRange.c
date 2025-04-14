/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomRange.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:26:22 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/14 18:13:16 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map_generator.h"

/* Random Range */
int	random_range_i(int min, int max)
{
	return (min + (rand() % (max - min + 1)));
}

size_t	random_range_u(size_t min, size_t max)
{
	return (min + (rand() % (max - min + 1)));
}
