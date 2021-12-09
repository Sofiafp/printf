/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:40:11 by salegre-          #+#    #+#             */
/*   Updated: 2021/11/24 12:27:22 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *s, ...);
void	write_args(char c, va_list args, int *cnt_byts);
int		what_is_after_percent(char c);
int		ft_put_hex(int n, int islwr);
int		ft_put_void_no(unsigned long n);
int		ft_putstr_fd(char const *s, int fd);
void	ft_putnbr_fd(int n, int fd);
int		ft_putchar_fd(char c, int fd);
int		ft_putnbr_fd_unsigned(unsigned int n, int fd);
int		get_n_alg(int n, int fd);

#endif
