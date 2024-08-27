# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlassere <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 19:58:15 by tlassere          #+#    #+#              #
#    Updated: 2024/08/27 20:05:45 by tlassere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	::= ft_ping

SRCS	::= main.c
OBJS	::= $(SRCS:.c=.o)
CFLAG	::= -Wall -Wextra -Werror
CC		::= cc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm $(OBJS)

fclean: clean
	rm $(NAME)

re: fclean all
