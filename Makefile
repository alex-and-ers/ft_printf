# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sebonie <sebonie@student.21-school.ru>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/25 14:23:27 by sebonie           #+#    #+#              #
#    Updated: 2021/11/25 14:23:39 by sebonie          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	ft_printf.c type_processing.c aux_funcs.c
OBJS		= $(SRCS:.c=.o)
HEADER		= ft_printf.h
NAME		= libftprintf.a

CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror

all:		$(NAME)

$(NAME): 	$(OBJS)
				ar rcs $(NAME) $?

%.o:		%.c $(HEADER)
				$(CC) $(FLAGS) -c $< -o $@

clean:
				$(RM) $(OBJS)

fclean:		clean
				$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re