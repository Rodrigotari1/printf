/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodrigo <rodrigo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 18:22:28 by rodrigo           #+#    #+#             */
/*   Updated: 2024/10/25 13:33:02 by rodrigo          ###   ########.fr       */
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

/*#include <stdio.h>
#include "ft_printf.h"

int main() {
    int ft_return, stdio_return;

    // Test case 1: Simple string
    printf("--- Test case 1 ---\n");
    ft_return = ft_printf("Hello, world!\n");
    stdio_return = printf("Hello, world!\n");
    printf("ft_printf return value: %d\n", ft_return);
    printf("printf return value: %d\n", stdio_return);

    // Test case 2: String with format specifiers
    printf("\n--- Test case 2 ---\n");
    ft_return = ft_printf("This is an %s with %d format specifiers.\n", "example", 2);
    stdio_return = printf("This is an %s with %d format specifiers.\n", "example", 2);
    printf("ft_printf return value: %d\n", ft_return);
    printf("printf return value: %d\n", stdio_return);

    // Test case 3: Character
    printf("\n--- Test case 3 ---\n");
    ft_return = ft_printf("The character is: %c\n", 'A');
    stdio_return = printf("The character is: %c\n", 'A');
    printf("ft_printf return value: %d\n", ft_return);
    printf("printf return value: %d\n", stdio_return);

    // Test case 4: Integer
    printf("\n--- Test case 4 ---\n");
    ft_return = ft_printf("The integer is: %d\n", 42);
    stdio_return = printf("The integer is: %d\n", 42);
    printf("ft_printf return value: %d\n", ft_return);
    printf("printf return value: %d\n", stdio_return);

    // Test case 5: Unsigned integer
    printf("\n--- Test case 5 ---\n");
    ft_return = ft_printf("The unsigned integer is: %u\n", 42);
    stdio_return = printf("The unsigned integer is: %u\n", 42);
    printf("ft_printf return value: %d\n", ft_return);
    printf("printf return value: %d\n", stdio_return);

    // Test case 6: Hexadecimal (lowercase)
    printf("\n--- Test case 6 ---\n");
    ft_return = ft_printf("The hexadecimal (lowercase) is: %x\n", 0xDEADBEEF);
    stdio_return = printf("The hexadecimal (lowercase) is: %x\n", 0xDEADBEEF);
    printf("ft_printf return value: %d\n", ft_return);
    printf("printf return value: %d\n", stdio_return);

    // Test case 7: Hexadecimal (uppercase)
    printf("\n--- Test case 7 ---\n");
    ft_return = ft_printf("The hexadecimal (uppercase) is: %X\n", 0xDEADBEEF);
    stdio_return = printf("The hexadecimal (uppercase) is: %X\n", 0xDEADBEEF);
    printf("ft_printf return value: %d\n", ft_return);
    printf("printf return value: %d\n", stdio_return);

    // Test case 8: Pointer
    printf("\n--- Test case 8 ---\n");
    int *ptr = NULL;
    ft_return = ft_printf("The pointer is: %p\n", ptr);
    stdio_return = printf("The pointer is: %p\n", ptr);
    printf("ft_printf return value: %d\n", ft_return);
    printf("printf return value: %d\n", stdio_return);

    // Test case 9: Percent sign
    printf("\n--- Test case 9 ---\n");
    ft_return = ft_printf("This is a percent sign: %%\n");
    stdio_return = printf("This is a percent sign: %%\n");
    printf("ft_printf return value: %d\n", ft_return);
    printf("printf return value: %d\n", stdio_return);

    return 0;
}*/