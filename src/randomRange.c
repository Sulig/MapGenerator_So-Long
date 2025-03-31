/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomRange.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:26:22 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/31 19:30:05 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/map_generator.h"

/* Random Range */
int	randomRange_i(int min, int max)
{
	return (min + (rand() % (max - min + 1)));
}

size_t	randomRange_u(size_t min, size_t max)
{
	return (min + (rand() % (max - min + 1)));
}
