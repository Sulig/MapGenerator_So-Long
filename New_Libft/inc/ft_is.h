/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadoming <sadoming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 18:35:29 by sadoming          #+#    #+#             */
/*   Updated: 2025/04/14 18:10:48 by sadoming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IS_H
# define FT_IS_H

/* IS ... */
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isascii(int c);
int		ft_is_cap(char c);
int		ft_isdigit(int c);
int		ft_isprint(int c);

int		ft_isnumeric(char *str);

/* IS... IN ALL */
int		ft_isalnum_all(char *str);
int		ft_isalpha_all(char *str);
int		ft_isascii_all(char *str);
int		ft_isdigit_all(char *str);
int		ft_isprint_all(char *str);
int		ft_is_cap_all(char *str);

#endif
