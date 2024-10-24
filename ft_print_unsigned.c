/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:32:40 by rodrigo           #+#    #+#             */
/*   Updated: 2024/10/24 16:17:43 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_unsigned(unsigned int n, size_t *counter)
{
	char	str[11];
	int		i;

	i = 10;
	str[i] = '\0';
	if (n == 0)
		str[--i] = '0';
	while (n > 0)
	{
		str[--i] = (n % 10) + '0';
		n /= 10;
	}
	return (ft_print_str(&str[i], counter));
}
