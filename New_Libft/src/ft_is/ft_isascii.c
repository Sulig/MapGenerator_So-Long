/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 11:59:45 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/31 19:14:12 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	else
		return (0);
}

int	ft_isascii_all(char *str)
{
	while (*str)
	{
		if (!ft_isascii(*str))
			return (0);
		str++;
	}
	return (1);
}
