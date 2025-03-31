/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:30:27 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/31 19:13:40 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if (c < 'A')
		return (0);
	else if (c > 'z')
		return (0);
	else if (c > 'Z' && c < 'a')
		return (0);
	else
		return (1);
}

int	ft_isalpha_all(char *str)
{
	while (*str)
	{
		if (!ft_isalpha(*str))
			return (0);
		str++;
	}
	return (1);
}
