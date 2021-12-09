# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: salegre- <salegre-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/22 19:19:34 by salegre-          #+#    #+#              #
#    Updated: 2021/11/24 15:06:47 by salegre-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
LIB1	= ar -rcs
LIB2	= ranlib
RM		= /bin/rm -f

NAME	= libftprintf.a

INCLUDE	= ft_printf.h
SRCS	= ft_printf.c auxiliar.c ft_putchar_fd.c ft_putnbr_fd.c ft_putstr_fd.c get_the_args.c \
			print_hex.c ft_putnbr_fd_unsigned.c
OBJS	= $(SRCS:.c=.o)

all:		$(NAME) clean

$(NAME):	$(OBJS) $(INCLUDE)
			$(LIB1) $(NAME) $(OBJS)
			$(LIB2) $(NAME)

.c.o:
			$(CC) $(CFLAGS) -I$(INCLUDE) -c $< -o $(<:.c=.o)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re