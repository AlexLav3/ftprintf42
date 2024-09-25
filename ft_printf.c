/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 14:00:34 by elavrich          #+#    #+#             */
/*   Updated: 2024/09/25 17:24:17 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.c"
#include "ft_putnbr.c"
#include "ft_putstr.c"
#include "libft.h"

char	check_arg(const char *format)
{
	while (*format)
	{
		if (*format == '%' && *(format + 1) == 'd')
			return ('d');
		if (*format == '%' && *(format + 1) == 's')
			return ('s');
		if (*format == '%' && *(format + 1) == 'f')
			return ('f');
		format++;
	}
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
	int	fact_int;

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
	factp = factp + 0.5;
	fact_int = (int)factp;
	ft_putnbr(fact_int);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		num;
	char	*str;
	double	nm;

	va_start(args, format);
	while (*format)
	{
		if (check_arg(format) == 'd')
		{
			num = va_arg(args, int);
			ft_putnbr(num);
		}
		else if (check_arg(format) == 's')
		{
			str = va_arg(args, char *);
			ft_putstr(str);
		}
		else if (check_arg(format) == 'f')
		{
			nm = va_arg(args, double);
			ft_putdouble(format, nm);
		}
		format++;
	}
	return (0);
}
int	main(void)
{
	ft_printf("%.2f", 1.4344756765765);
	printf("\n%.2f", 1.4344756765765);
}
//%f without specifiers works, but does not if I put one (ex. 2f)
