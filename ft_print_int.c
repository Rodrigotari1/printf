/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:24:47 by rodrigo           #+#    #+#             */
/*   Updated: 2024/10/24 11:48:28 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putnbr_recursive(long n, size_t *counter)
{
	int	result;

	result = 0;
	if (n < 0)
	{
		if (ft_print_char('-', counter) == -1)
			return (-1);
		n = -n;
	}
	if (n >= 10)
	{
		result = ft_putnbr_recursive(n / 10, counter);
		if (result == -1)
			return (-1);
	}
	return (ft_print_char(n % 10 + '0', counter));
}

int	ft_print_int(int n, size_t *counter)
{
	if (n == -2147483648)
		return (ft_putstr_pf("-2147483648", counter));
	return (ft_putnbr_recursive(n, counter));
}
