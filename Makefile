# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hamchur <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/25 17:33:54 by hamchur           #+#    #+#              #
#    Updated: 2022/02/20 17:08:02 by hamchur          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Wextra -Werror -pthread

SRC = sources/args.c \
	  sources/initing_mutex.c \
	  sources/initing_thread.c \
	  sources/philo.c \
	  sources/routine.c \
	  sources/still_alive.c \
	  sources/utils.c

OBJ = $(SRC:.c=.o)

INCLD = philosophers.h

%.o: %.c
	gcc -g $(FLAGS) -I$(INCLD) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(FLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all re clean fclean
