# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: masalaib <marvin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/06/18 20:15:30 by masalaib          #+#    #+#              #
#    Updated: 2026/07/02 17:50:07 by dilferre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Werror -Wextra -g
RM = rm -rf

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
LIBS = -lreadline $(LIBFT_LIB)

SRC_DIR = src
ALGO_DIR = $(SRC_DIR)/Algorithms
DATA_DIR = $(SRC_DIR)/Data
DESORDER_DIR = $(SRC_DIR)/Desorder
PARSER_DIR = $(SRC_DIR)/Parsing
RUN_DIR = $(SRC_DIR)/Run
STACK_DIR = $(SRC_DIR)/Stack
OPTIONS_DIR = $(SRC_DIR)/options

SRCS = $(PARSER_DIR)/verify.c \
	   $(PARSER_DIR)/atol.c \
	   $(PARSER_DIR)/metrics.c \
	   $(STACK_DIR)/create_stack.c \
	   $(STACK_DIR)/stack.c \
	   $(DESORDER_DIR)/desorder.c \
	   $(OPTIONS_DIR)/options.c \
	   $(DATA_DIR)/data.c \
	   $(RUN_DIR)/ops_swap.c \
	   $(RUN_DIR)/ops_push.c \
	   $(RUN_DIR)/r_moves.c \
	   $(RUN_DIR)/reverse_r_moves.c \
	   $(ALGO_DIR)/sort_simple.c \
	   $(ALGO_DIR)/sort_small.c \
	   main.c

OBJS = $(SRCS:.c=.o)

all: libft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

libft:
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS)
	make clean -C $(LIBFT_DIR)

fclean: clean
	$(RM) $(NAME)
	make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re libft
