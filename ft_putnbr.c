/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:56:18 by elavrich          #+#    #+#             */
/*   Updated: 2024/09/26 20:02:32 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr(int n)
{
	char	num;
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (1);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		n = -n;
		i++;
	}
	if (n >= 10)
	{
		ft_putnbr(n / 10);
		i++;
	}
	num = (n % 10) + '0';
	write(1, &num, 1);
	return (i);
}
// int main()
// {
// 	ft_putnbr_fd(-21474848, -1);
// }
