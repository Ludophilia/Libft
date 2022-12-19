# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 13:02:44 by jgermany          #+#    #+#              #
#    Updated: 2022/12/19 22:52:57 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CCFL = -Wall -Wextra -Werror
SRCFL = -c
OUTFL = -o
INCFL = -I

AR = ar
ARFL = -rcs

INCDIR = .
CMN = $(wildcard ft_[abcimpst]*.c)
CBN = $(wildcard ft*_bonus.c)
OBMN = $(CMN:.c=.o)

all: $(NAME)
$(NAME): $(OBMN)
	$(AR) $(ARFL) $@ $^
%.o: %.c
	$(CC) $(CCFL) $(INCFL)$(INCDIR) $(SRCFL) $< $(OUTFL) $@

test_%: all
	$(CC) $(CCFL) $(INCFL)$(INCDIR) -lft -L. tests/$@.c && ./a.out
	rm a.out

re: fclean all
fclean: clean
	rm $(NAME)
clean:
	rm $(OBMN)
xclean:
	rm $(NAME)

bonus:
	@echo "bonus are there, but there is still work to do ;)"
.PHONY: all clean fclean xclean re bonus test_%
