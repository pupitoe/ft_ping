# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlassere <tlassere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/27 19:58:15 by tlassere          #+#    #+#              #
#    Updated: 2025/08/15 15:02:26 by tlassere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	::= ft_ping

SRCS	::= main.c ft_args.c ft_data.c
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
