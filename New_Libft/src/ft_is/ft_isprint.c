/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 12:07:29 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/31 19:16:26 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c < ' ' || c > '~')
		return (0);
	else
		return (1);
}

int	ft_isprint_all(char *str)
{
	while (*str)
	{
		if (!ft_isprint(*str))
			return (0);
		str++;
	}
	return (1);
}
