/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_the_args.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:39:29 by salegre-          #+#    #+#             */
/*   Updated: 2021/11/24 20:20:15 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	write_args(char c, va_list args, int *cnt_byts)
{
	if (c == 'c')
		*cnt_byts += ft_putchar_fd(va_arg(args, int), 1);
	if (c == 's')
		*cnt_byts += ft_putstr_fd(va_arg(args, char *), 1);
	if (c == 'd' || c == 'i')
		*cnt_byts += get_n_alg(va_arg(args, int), 1);
	if (c == 'X')
		*cnt_byts += ft_put_hex(va_arg(args, int), 0);
	if (c == 'x')
		*cnt_byts += ft_put_hex(va_arg(args, int), 32);
	if (c == '%')
		*cnt_byts += ft_putchar_fd('%', 1);
	if (c == 'u')
		*cnt_byts += ft_putnbr_fd_unsigned(va_arg(args, unsigned int), 1);
	if (c == 'p')
	{
		ft_putstr_fd("0x", 1);
		*cnt_byts += ft_put_void_no(va_arg(args, unsigned long));
	}
}
