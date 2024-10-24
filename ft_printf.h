/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:37:10 by rodrigo          #+#    #+#             */
/*   Updated: 2024/10/24 16:12:36 by rodrigo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_print_char(int c, size_t *counter);
int		ft_print_str(char *str, size_t *counter);
int		ft_print_ptr(void *ptr, size_t *counter);
int		ft_print_int(int n, size_t *counter);
int		ft_print_unsigned(unsigned int n, size_t *counter);
int		ft_print_hex(unsigned int n, char format, size_t *counter);
int		ft_print_percent(size_t *counter);
size_t	ft_strlen(const char *s);
int		ft_putstr_pf(char *str, size_t *counter);

#endif
