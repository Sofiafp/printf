/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_hex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 12:07:26 by salegre-          #+#    #+#             */
/*   Updated: 2021/11/24 20:34:34 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_printf.h"

void	make_the_choice(int n, int islwr)
{
	if (n < 10)
		ft_putnbr_fd(n, 1);
	else
	{
		if (n == 10)
			ft_putchar_fd('A' + islwr, 1);
		if (n == 11)
			ft_putchar_fd('B' + islwr, 1);
		if (n == 12)
			ft_putchar_fd('C' + islwr, 1);
		if (n == 13)
			ft_putchar_fd('D' + islwr, 1);
		if (n == 14)
			ft_putchar_fd('E' + islwr, 1);
		if (n == 15)
			ft_putchar_fd('F' + islwr, 1);
	}
}

int	ft_put_hex_neg(int n, int islwr)
{
	unsigned int	num;
	int				no_iter;
	int				cnt_byts;
	int				count;

	no_iter = 0;
	num = n;
	cnt_byts = 0;
	while ((num / 16) > 0)
	{
		num = num / 16;
		no_iter++;
	}
	make_the_choice(num, islwr);
	cnt_byts++;
	while (no_iter-- > 0)
	{
		num = n;
		count = no_iter;
		while (count-- > 0)
			num = num / 16;
		make_the_choice((num % 16), islwr);
		cnt_byts++;
	}
	return (cnt_byts);
}

int	no_iteration(int num, int *no_iter)
{
	while ((num / 16) > 0)
	{
		num = num / 16;
		(*no_iter)++;
	}
	return (num);
}

int	ft_put_hex(int n, int islwr)
{
	int	count;
	int	no_iter;
	int	num;
	int	cnt_byts;

	no_iter = 0;
	cnt_byts = 0;
	if (n < 0)
		return (ft_put_hex_neg((unsigned int)n, islwr));
	num = no_iteration(n, &no_iter);
	make_the_choice(num, islwr);
	cnt_byts++;
	while (no_iter-- > 0)
	{
		num = n;
		count = no_iter;
		while (count-- > 0)
			num = num / 16;
		make_the_choice((num % 16), islwr);
		cnt_byts++;
	}
	return (cnt_byts);
}
