/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arrcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:03:48 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/16 12:17:37 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/arrays.h"
#include "../../inc/memory.h"

/* Creates an array of type `char **` */
char	**ft_arr_strcreate(size_t heigth, size_t width)
{
	char	**new_arr;
	size_t	i;

	i = 0;
	if (!heigth || !width)
		return (NULL);
	new_arr = ft_calloc(heigth + 1, sizeof(char *));
	if (!new_arr)
		return (NULL);
	while (i < heigth)
	{
		new_arr[i] = ft_calloc(width + 1, sizeof(char ));
		if (!new_arr)
		{
			new_arr = ft_free_arrstr(new_arr);
			return (NULL);
		}
		i++;
	}
	return (new_arr);
}
