/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:39:24 by salegre-          #+#    #+#             */
/*   Updated: 2021/11/24 22:39:19 by salegre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	send_flags(char *s, va_list	args)
{
	int		i;
	int		cnt_bts;

	i = 0;
	cnt_bts = 0;
	while (s[i] != '\0')
	{
		if (s[i] != '%')
		{
			write(1, &s[i++], 1);
			cnt_bts++;
		}
		else
			if (what_is_after_percent(s[++i]))
				write_args(s[i++], args, &cnt_bts);
	}
	return (cnt_bts);
}
// o protótipo é /int ft_printf(const char *, ...)/ mas isso dá me erro sem o s!
// Eles enganaram-se, ou sou eu que estou mal?

int	ft_printf(const char *s, ...)
{
	char	*bleh;
	va_list	args;
	int		cnt_byts;

	cnt_byts = 0;
	va_start(args, s);
	bleh = (char *)s;
	cnt_byts = send_flags(bleh, args);
	va_end(args);
	return (cnt_byts);
}

#include <limits.h>
int main()
{
	//int	d  = 1;
	//char	*str = NULL;
	//char	c1 = '0';
	//char	c2 = '1';
	//int	hex = 23672367;
	//void *ptr = "ffjf";
	//unsigned int	u = 456756;
	int len1;
	int	len2;

	//char *to_print = " %c %c \n";

	len1 = ft_printf(" %X \n", 100);
	len2 = printf(" %X \n", 100);

	printf("len1: %d\nlen2: %d", len1, len2);

}
