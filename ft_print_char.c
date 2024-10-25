/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:30:00 by rodrigo           #+#    #+#             */
/*   Updated: 2024/10/25 14:20:09 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_char(int c, size_t *counter)
{
	char	ch;

	ch = (char)c;
	if (write(1, &ch, 1) == -1)
		return (-1);
	(*counter)++;
	return (0);
}
