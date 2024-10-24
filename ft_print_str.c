/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:23:39 by rodrigo           #+#    #+#             */
/*   Updated: 2024/10/22 17:31:22 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(char *str, size_t *counter)
{
	if (!str)
		return (ft_putstr_pf("(null)", counter));
	return (ft_putstr_pf(str, counter));
}
