/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elavrich <elavrich@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 19:56:16 by elavrich          #+#    #+#             */
/*   Updated: 2024/09/26 22:40:24 by elavrich         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s, const char *format)
{
	int	i;

	i = 0;
	(void)format;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}
