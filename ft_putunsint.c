/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 16:17:37 by elavrich          #+#    #+#             */
/*   Updated: 2024/09/26 16:21:07 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void ft_putunsint(unsigned n)
{
	char	num;

	if (n >= 10)
		ft_putnbr(n / 10);
	num = (n % 10) + '0';
	write(1, &num, 1);
}
