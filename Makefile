# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 13:02:44 by jgermany          #+#    #+#              #
#    Updated: 2022/12/13 15:57:57 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CCFL = -Wall -Wextra -Werror
OBFL = -c
OUTFL = -o
INCFL = -I

AR = ar
ARFL = -rcs

INCLUDES = ./
CMAN = $(wildcard ft_[abcimpst]*.c)
CBON = $(wildcard ft*_bonus.c)
OBFILES = $(CMAN:.c=.o)

all: $(NAME)
$(NAME): $(OBFILES) #BROKEN, AS OBFILES DOESN'T WORK
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
	@echo "bonus are there, but there is still work to do ;)"

.PHONY: all clean fclean xclean re bonus
