/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/10 19:05:41 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/31 19:12:01 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_cap(char c)
{
	if (c > '/' && c < ':')
		return (1);
	if (c > '@' && c < '[')
		return (1);
	return (0);
}

int	ft_is_cap_all(char *str)
{
	while (*str)
	{
		if (!ft_is_cap(*str))
			return (0);
		str++;
	}
	return (1);
}
