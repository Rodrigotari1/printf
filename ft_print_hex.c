/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:34:14 by rodrigo           #+#    #+#             */
/*   Updated: 2024/10/24 16:03:44 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_puthex_recursive(unsigned int n, char *base, size_t *counter)
{
	int	result;

	if (n >= 16)
	{
		result = ft_puthex_recursive(n / 16, base, counter);
		if (result == -1)
			return (-1);
	}
	return (ft_print_char(base[n % 16], counter));
}

int	ft_print_hex(unsigned int n, char format, size_t *counter)
{
	char	*base;

	if (format == 'x')
		base = "0123456789abcdef";
	else
		base = "0123456789ABCDEF";
	if (n == 0)
		return (ft_print_char('0', counter));
	return (ft_puthex_recursive(n, base, counter));
}
