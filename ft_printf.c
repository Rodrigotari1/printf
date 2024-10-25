/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:22:28 by rodrigo           #+#    #+#             */
/*   Updated: 2024/10/25 14:58:17 by rodrigo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	handle_format(char specifier, va_list *args, size_t *counter)
{
	if (specifier == 'c')
		return (ft_print_char(va_arg(*args, int), counter));
	else if (specifier == 's')
		return (ft_print_str(va_arg(*args, char *), counter));
	else if (specifier == 'p')
		return (ft_print_ptr(va_arg(*args, void *), counter));
	else if (specifier == 'd' || specifier == 'i')
		return (ft_print_int(va_arg(*args, int), counter));
	else if (specifier == 'u')
		return (ft_print_unsigned(va_arg(*args, unsigned int), counter));
	else if (specifier == 'x' || specifier == 'X')
		return (ft_print_hex(va_arg(*args, unsigned int), specifier, counter));
	else if (specifier == '%')
		return (ft_print_char('%', counter));
	return (0);
}

static int	process_format(const char **format, va_list *args, size_t *counter)
{
	int	result;

	if (**format == '%' && *(*format + 1))
	{
		(*format)++;
		result = handle_format(**format, args, counter);
	}
	else
		result = ft_print_char(**format, counter);
	return (result);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	size_t	counter;
	int		result;

	if (!format)
		return (-1);
	va_start(args, format);
	counter = 0;
	while (*format)
	{
		result = process_format(&format, &args, &counter);
		if (result == -1)
		{
			va_end(args);
			return (-1);
		}
		format++;
	}
	va_end(args);
	return (counter);
}

/*#include "ft_printf.h"

int main() {
    ft_printf("Character: %c, String: %s, Integer: %d\n", 'A', "Hello", 42);
    ft_printf("Unsigned integer: %u, Hexadecimal (lower): %x\n", 1234, 0xDEADBEEF);
    ft_printf("Hexadecimal (upper): %X, Pointer: %p\n", 0xDEADBEEF, (void *)&main);
    ft_printf("Percent sign: %%\n");
    return 0;
}*/