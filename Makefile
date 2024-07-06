# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sramis-c <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/29 13:22:28 by sramis-c          #+#    #+#              #
#    Updated: 2021/11/29 13:35:27 by sramis-c         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= philo

SRC_DIR		= src/

SRC			= main.c get_args.c philo.c eat.c routine.c

SRC_F		= $(addprefix $(SRC_DIR), $(SRC))

OBJ			= $(SRC_F:%.c=%.o)

INCLUDE		= -I ./include

CC			= gcc 

CFLAGS		= -Wall -Wextra -Werror -pthread -g3

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) $(INCLUDE) -o $@ -c $^

$(NAME):	$(OBJ) include/philo.h
			$(CC) $(CFLAGS) $(INCLUDE) $(OBJ) -o $(NAME)

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all
