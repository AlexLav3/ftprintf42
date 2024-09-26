/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexlower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:30:50 by elavrich          #+#    #+#             */
/*   Updated: 2024/09/26 16:33:29 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_hexlower(int n)
{
	char			*symbols;
	int	value;

	value = 0;
	symbols = "0123456789abcdef";
	if (n >= 16)
	{
		value += ft_hexlower(n / 16);
	}
	value += write(1, &symbols[n % 16], 1);
	return (value);
}
