/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:00:34 by elavrich          #+#    #+#             */
/*   Updated: 2024/10/01 20:33:49 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;

	count = 0;
	va_start(args, format);
	while (*format)
	{
		if (ft_c(format) == 'd' || ft_c(format) == 'i' || ft_c(format) == 'u')
			count += ft_chosenbr(va_arg(args, int), format++);
		else if (ft_c(format) == 's')
			count += ft_putstr(va_arg(args, char *), format++);
		else if (ft_c(format) == 'p')
			count += ft_vptr((unsigned long)va_arg(args, void *), format++);
		else if (ft_c(format) == '%')
			count += ft_putchar((char) '%', format++);
		else if (ft_c(format) == 'c')
			count += ft_putchar((char)va_arg(args, int), format++);
		else if (ft_c(format) == 'x' || ft_c(format) == 'X')
			count += ft_chosehex(va_arg(args, int), format++);
		else
			count += ft_putchar_onear(*format);
		format++;
	}
	va_end(args);
	return (count);
}

// int	main(void)
// {
// 	int	a;
// 	int	*ptr;

// 	a = 4;
// 	ptr = &a;

// 	// ft_printf(" %u ", a);
// 	// ft_printf(" %u ", a);

// 	// ft_printf(" %d ", a);
// 	// printf(" %d ", a);

// 	// ft_printf(" %i ", a);
// 	// printf(" %i ", a);

// 	ft_printf(" %x ", 455);
// 	printf(" %x ", 455);

// 	ft_printf(" %X ", 455);
// 	printf(" %X ", 455);

// 	// ft_printf(" %p ", ptr);
// 	// printf(" %p ", ptr);

// 	// ft_printf(" %c ", 'a');
// 	// printf(" %c ", 'a');

// 	// ft_printf(" %s ", "string");
// 	// printf(" %s ", "string");

// 	// ft_printf(" %% ");
// 	// printf(" %% ");

// 	// ft_printf("%d", ft_printf(" %u ", a));
// 	// printf("%d", printf(" %u ", a));
// 	// //printf("%d", printf("| NULL %s NULL |\n", NULL));
// 	// ft_printf("%d", ft_printf("| NULL %s NULL |\n", NULL));
// }
