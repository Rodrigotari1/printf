/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_pf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 19:00:00 by rodrigo           #+#    #+#             */
/*   Updated: 2024/10/19 18:55:59 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_pf(char *str, size_t *counter)
{
	if (!counter)
		return (-1);
	if (!str)
		return (ft_putstr_pf("(null)", counter));
	while (*str)
	{
		if (ft_print_char(*str, counter) == -1)
			return (-1);
		str++;
	}
	return (0);
}
