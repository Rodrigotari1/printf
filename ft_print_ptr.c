/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:27:48 by rodrigo           #+#    #+#             */
/*   Updated: 2024/10/25 13:29:12 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_putptr_recursive(unsigned long n, size_t *counter)
{
	char	*base;
	int		result;

	base = "0123456789abcdef";
	if (n >= 16)
	{
		result = ft_putptr_recursive(n / 16, counter);
		if (result == -1)
			return (-1);
	}
	return (ft_print_char(base[n % 16], counter));
}

int	ft_print_ptr(void *ptr, size_t *counter)
{
	unsigned long	ptr_address;

	if (!ptr)
		return (ft_putstr_pf("0x0", counter));
	ptr_address = (unsigned long)ptr;
	if (ft_putstr_pf("0x", counter) == -1)
		return (-1);
	return (ft_putptr_recursive(ptr_address, counter));
}