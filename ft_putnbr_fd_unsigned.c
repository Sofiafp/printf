/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd_unsigned.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 14:10:44 by salegre-          #+#    #+#             */
/*   Updated: 2021/11/24 14:43:37 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	nchar_unsigned(unsigned int n)
{
	int	count;

	count = 0;
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}

int	power_unigned(int count)
{
	int	a;

	a = 1;
	while (count > 0)
	{
		a *= 10;
		count--;
	}
	return (a);
}

int	ft_putnbr_fd_unsigned(unsigned int n, int fd)
{
	int				count;
	unsigned int	a;
	int				return_count;

	return_count = nchar_unsigned(n);
	if (n == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	count = nchar_unsigned(n) - 1;
	while (count > 0)
	{
		a = n / (power_unigned(count));
		ft_putnbr_fd_unsigned(a, fd);
		n = n - a * (power_unigned(count));
		count--;
	}
	ft_putchar_fd((n % 10) + 48, fd);
	return (return_count);
}
