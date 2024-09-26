/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexupper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:34:38 by elavrich          #+#    #+#             */
/*   Updated: 2024/09/26 22:40:40 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexupper(int n, const char *format)
{
	char	*symbols;
	int		value;

	value = 0;
	symbols = "0123456789ABCDEF";
	if (n >= 16)
	{
		value += ft_hexupper(n / 16, format);
	}
	value += write(1, &symbols[n % 16], 1);
	return (value);
}
