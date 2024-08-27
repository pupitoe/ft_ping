# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlassere <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 19:58:15 by tlassere          #+#    #+#              #
#    Updated: 2024/08/27 22:48:58 by tlassere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	::= ft_ping

SRCS	::= main.c ft_args.c
OBJS	::= $(SRCS:.c=.o)
CFLAGS	::= -Wall -Wextra -Werror
CC		::= cc

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all
