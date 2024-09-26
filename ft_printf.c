/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:00:34 by elavrich          #+#    #+#             */
/*   Updated: 2024/09/26 16:25:56 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.c"
#include "ft_check_arg.c"
#include "ft_pointer.c"
#include "ft_putchar.c"
#include "ft_putnbr.c"
#include "ft_putstr.c"
#include "ft_putunsint.c"
#include "ft_strlen.c"
#include "libft.h"

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		num;
	char	*str;
	double	nm;
	char	ch;
	void	*ptr;
	char	*hex_str;

	va_start(args, format);
	while (*format)
	{
		if (ft_check_arg(format) == 'd' || ft_check_arg(format) == 'i')
		{
			num = va_arg(args, int);
			ft_putnbr(num);
		}
		else if (ft_check_arg(format) == 'u')
		{
			num = va_arg(args, unsigned int);
			ft_putunsint(num);
		}
		else if (ft_check_arg(format) == 's')
		{
			str = va_arg(args, char *);
			ft_putstr(str);
		}
		else if (ft_check_arg(format) == 'p')
		{
			ptr = va_arg(args, void *);
			ft_print_void_pointer((unsigned long)ptr);
		}
		else if (ft_check_arg(format) == '%')
		{
			ch = '%';
			ft_putchar((char)ch);
		}
		else if (ft_check_arg(format) == 'c')
		{
			ch = va_arg(args, int);
			ft_putchar((char)ch);
		}
		else if (ft_check_arg(format) == 'x')
		{
		}
		format++;
	}
	return (0);
}
int	main(void)
{
	unsigned int	a;

	// int	*ptr;
	a = 9;
	// ptr = &a;
	ft_printf("%u", a);
	printf("\n%u", a);
}
// x = unsigned hexadecimal base (base 16)
// X = unsigned hexadecimal integer (uppercase)
