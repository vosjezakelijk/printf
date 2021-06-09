# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hsamatha <hsamatha@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/03/02 18:14:49 by hsamatha          #+#    #+#              #
#    Updated: 2021/03/05 19:28:44 by hsamatha         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = ft_printf.h

SRCS = ft_printf.c ft_execute.c ft_flag_parser.c ft_type_parser.c\
		flag_minus.c flag_precision.c flag_width.c flag_zero.c\
		percent.c spec_c.c spec_i_d.c spec_p.c spec_s.c\
		spec_u.c spec_upper_x.c spec_x.c\
		utils.c utils2.c utils3.c utils4.c\

OBJS = $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

all:	$(NAME)

$(NAME):	$(OBJS) $(HEADER)
	ar rc $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean:	clean
	$(RM) $(NAME)

re:	fclean all

.PHONY:	all clean fclean re
