/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   auxiliar.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:39:14 by salegre-          #+#    #+#             */
/*   Updated: 2021/11/22 19:38:58 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	what_is_after_percent(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u' \
		|| c == 'x' || c == 'X' || c == '%' || c == 'u' || c == 'i')
		return (1);
	return (0);
}

void	make_it_hex(unsigned long ul)
{
	int	n;

	n = (int)ul;
	if (n < 10)
		ft_putnbr_fd(n, 1);
	else
	{
		if (n == 10)
			ft_putchar_fd('a', 1);
		if (n == 11)
			ft_putchar_fd('b', 1);
		if (n == 12)
			ft_putchar_fd('c', 1);
		if (n == 13)
			ft_putchar_fd('d', 1);
		if (n == 14)
			ft_putchar_fd('e', 1);
		if (n == 15)
			ft_putchar_fd('f', 1);
	}
}

int	ft_put_void_no(unsigned long n)
{
	int				count;
	int				no_iter;
	unsigned long	num;
	int				prt_rtn;

	prt_rtn = 2;
	no_iter = 0;
	num = n;
	while ((num / 16) > 0)
	{
		num = num / 16;
		no_iter++;
	}
	make_it_hex(num);
	prt_rtn++;
	while (no_iter-- > 0)
	{
		num = n;
		count = no_iter;
		while (count-- > 0)
			num = num / 16;
		make_it_hex(num % 16);
		prt_rtn++;
	}
	return (prt_rtn);
}
