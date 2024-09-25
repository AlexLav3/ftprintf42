/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:00:34 by elavrich          #+#    #+#             */
/*   Updated: 2024/09/25 22:09:28 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.c"
#include "ft_putchar.c"
#include "ft_putnbr.c"
#include "ft_putstr.c"
#include "ft_strlen.c"
#include "libft.h"

char	check_arg(const char *format)
{
	int	length;

	length = ft_strlen(format) - 1;
	if (*format == '%' && *(format + 1) == 'd')
		return ('d');
	if (*format == '%' && *(format + 1) == 's')
		return ('s');
	if (*format == '%' && *(format + 1) == 'i')
		return ('i');
	if (*format == '%' && *(format + 1) == '%')
		return ('%');
	if (format[length] == 'f')
		return ('f');
	if (*format == '%' && *(format + 1) == 'c')
		return ('c');
	if (*format == '%' && *(format + 1) == 'p')
		return ('c');
	format++;
	return ('\0');
}

int	get_decimals(const char *format)
{
	int	decimals;

	decimals = 6;
	while (*format)
	{
		if (*format == '.')
		{
			decimals = ft_atoi(format + 1);
		}
		format++;
	}
	return (decimals);
}
void	ft_putdouble(const char *format, double n)
{
	int	intp;
	int	factp;
	int	mulp;
	int	i;
	int	decm;

	decm = get_decimals(format);
	i = 0;
	mulp = 1;
	intp = (int)n;
	ft_putnbr(intp);
	write(1, ".", 1);
	while (i < decm)
	{
		mulp = 10 * mulp;
		i++;
	}
	factp = (n - intp) * mulp;
	if (factp < 0)
		factp = -factp;
	ft_putnbr(factp);
}
char	*hexadecimal(void *ptr)
{
	unsigned long	temp;
	unsigned long	intptr;
	char			*result;
	int				i;
	char			*hex_chars = "0123456789ABCDEF";

	result = malloc(17);
	intptr = (unsigned long)ptr;
	i = 0;
	while (i < 15)
	{
		temp = intptr % 16;
		result[i] = hex_chars[temp];
		intptr /= 16;
		i++;
	}
	result[16] = '\0';
	return (result);
}

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
		if (check_arg(format) == 'd' || check_arg(format) == 'i')
		{
			num = va_arg(args, int);
			ft_putnbr(num);
		}
		else if (check_arg(format) == 's')
		{
			str = va_arg(args, char *);
			ft_putstr(str);
		}
		else if (check_arg(format) == 'p')
		{
			ptr = va_arg(args, void *);
			hex_str = hexadecimal(ptr);
			ft_putstr(hex_str);
		}
		else if (check_arg(format) == '%')
		{
			ch = '%';
			ft_putchar((char)ch);
		}
		else if (check_arg(format) == 'c')
		{
			ch = va_arg(args, int);
			ft_putchar((char)ch);
		}
		else if (check_arg(format) == 'f')
		{
			nm = va_arg(args, double);
			ft_putdouble(format, nm);
			return (0);
		}
		format++;
	}
	return (0);
}
int	main(void)
{
	int	a;
	int	*ptr;

	a = 2;
	ptr = &a;
	ft_printf("%p", ptr);
	printf("\n%p", ptr);
}
// p = an adress (or pointer)
// u = int unsigned decimal
// x = unsigned hexadecimal base (base 16)
// X = unsigned hexadecimal integer (uppercase)
//test
