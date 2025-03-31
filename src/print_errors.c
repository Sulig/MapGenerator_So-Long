/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 19:51:53 by sadoming          #+#    #+#             */
/*   Updated: 2025/03/31 20:03:10 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../inc/map_generator.h"

/* Print Malloc error */
void	print_errmalloc(void)
{
	ft_printf_fd(STDERR_FILENO, RR);
	ft_printf_fd(2, MALLOC_ERROR);
	ft_printf_fd(2, D);
	exit(EXIT_FAILURE);
}

/* Print Custom Error */
void	print_custom_err(char *err)
{
	ft_printf_fd(2, R);
	ft_printf_fd(2, err);
	ft_printf_fd(2, D);
	exit(EXIT_FAILURE);
}
