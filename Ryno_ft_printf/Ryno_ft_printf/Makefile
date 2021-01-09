# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rmeiboom <marvin@codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/02 13:21:55 by rmeiboom      #+#    #+#                  #
#    Updated: 2021/01/08 17:18:51 by rmeiboom      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

CC=gcc

CFLAGS = -Wall -Werror -Wextra

NAME = libftprintf.a

HEADERS = ft_printf.h

OBJ = 	ft_printf_utils.o\
		ft_printf.o\
		handle_flags.o\
		handle_type.o\
		type_conversions.o\
		handle_num.o

all: $(NAME)

$(NAME): 	$(OBJ)
			ar rc $@ $^
			ranlib $@

%.o: 		%.c $(HEADERS)
			$(CC) -c $(CFLAGS) -o $@ $<

clean:
			rm -f $(OBJ)

fclean:		clean
			rm -f $(NAME)

re:			fclean all

.PHONY: all clean fclean re bonus