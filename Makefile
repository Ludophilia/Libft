# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 13:02:44 by jgermany          #+#    #+#              #
#    Updated: 2022/12/01 11:56:49 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CCFL = -Wall -Wextra -Werror
OBFL = -c
# OUTFL = -o
INCFL = -I

AR = ar
ARFL = -rcs

# SRCS = ./srcs
INCLUDES = ./
CFILES = $(wildcard $(SRCS)/ft*.c)
OBFILES = $(CFILES:.c=.o)

all: $(NAME)
$(NAME): $(OBFILES)
	$(AR) $(ARFL) $@ $^
%.o: %.c
	$(CC) $(CCFL) $(INCFL)$(INCLUDES) $(OBFL) $< $(OUTFL) $@

re: fclean all
fclean: clean
	rm $(NAME)
clean:
	rm $(OBFILES)

xclean:
	rm $(NAME)

bonus:
	echo "bonus under construction ;)"

.PHONY: all clean fclean xclean re bonus
