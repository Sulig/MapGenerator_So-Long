/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 19:50:02 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/16 16:51:37 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include <stdlib.h>

/* BASES */
# define BASE_2		"01"
# define BASE_8		"01234567"
# define BASE_10	"0123456789"
# define BASE_16	"0123456789abcdef"
# define BASE_16_UP	"0123456789ABCDEF"

/* CONVERSIONS */
int		ft_atoi(const char *str);
long	ft_atol(const char *str);
size_t	ft_atos(const char *str);

char	*ft_itoa(int n);
char	*ft_itoa_unsig(size_t n, char *base);
char	*ft_unsig_tobase(size_t num, char base);

int		ft_toupper(int c);
int		ft_tolower(int c);
char	*ft_toupper_all(char *str);
char	*ft_tolower_all(char *str);
char	*ft_strcapitalize(char *str);

#endif
