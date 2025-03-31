/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 19:45:31 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/31 19:13:05 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if (c < '0')
		return (0);
	else if (c > 'z')
		return (0);
	else if (c > '9' && c < 'A')
		return (0);
	else if (c > 'Z' && c < 'a')
		return (0);
	else
		return (1);
}

int ft_isalnum_all(char *str)
{
	while (*str)
	{
		if (!ft_isalnum(*str))
			return (0);
		str++;
	}
	return (1);
}
