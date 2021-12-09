#include "ft_printf.h"
void	make_it_hex(int n)
{
	if (n < 10)
		ft_putnbr_fd(n, 1);
	else
	{
		if (n == 10)
			ft_putchar_fd('A', 1);
		if (n == 11)
			ft_putchar_fd('B', 1);
		if (n == 12)
			ft_putchar_fd('C', 1);
		if (n == 13)
			ft_putchar_fd('D', 1);
		if (n == 14)
			ft_putchar_fd('E', 1);
		if (n == 15)
			ft_putchar_fd('F', 1);
	}
}

void	ft_puthex(int n)
{
	int	count;
	int	no_iter;
	int	num;

	no_iter = 0;
	num = n;
	while ((num / 16) > 0)
	{
		num = num / 16;
		no_iter++;
	}
	make_it_hex(num);
	while (no_iter-- > 0)
	{
		num = n;
		count = no_iter;
		while (count-- > 0)
			num = num / 16;
		make_it_hex(num % 16);
	}
}

int main()
{
	ft_puthex(48234);
}