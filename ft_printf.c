/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:00:34 by elavrich          #+#    #+#             */
/*   Updated: 2024/09/26 23:27:27 by elavrich         ###   ########.fr       */
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
		if (ft_check_arg(format) == 'd' || ft_check_arg(format) == 'i'|| ft_check_arg(format) == 'u')
			count += ft_chosenbr(va_arg(args, int), format++);
		else if (ft_check_arg(format) == 's')
			count += ft_putstr(va_arg(args, char *), format++);
		else if (ft_check_arg(format) == 'p')
			count += ft_print_void_pointer((unsigned long)va_arg(args, void *),format++);
		else if (ft_check_arg(format) == '%')
			count += ft_putchar((char)'%', format++);
		else if (ft_check_arg(format) == 'c')
			count += ft_putchar((char)va_arg(args, int), format++);
		else if (ft_check_arg(format) == 'x' || ft_check_arg(format) == 'X')
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

// 	a = -456;
// 	ptr = &a;
// 	ft_printf(" %x ", -1);
// 	printf("\n%x ", -1);
// }
