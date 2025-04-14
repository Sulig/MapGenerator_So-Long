/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 20:13:44 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/14 20:19:46 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/arrays.h"
#include "../../inc/memory.h"
#include "../../inc/lenght.h"

/*
 * Copy the src array to the dest array
 * *Return NULL if !src || !dest
 * *Return dest
 * ** This will not reserve memory for dest
 * ** Use ft_arrdup if you want to reserve memory
*/
char	**ft_arrcpy(char **dest, char **src)
{
	size_t	i;

	if (!dest || !src)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = ft_memcpy(dest[i], src[i], ft_strlen(src[i]));
		i++;
	}
	dest[i] = NULL;
	return (dest);
}
