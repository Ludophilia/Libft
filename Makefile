# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 13:02:44 by jgermany          #+#    #+#              #
#    Updated: 2022/12/25 16:13:12 by jgermany         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CC = gcc
CCFL = -Wall -Wextra -Werror

INCDIR = .
LIB = ft
LIBDIR = .

CM = $(wildcard ft_[abcimpst]*.c)
OBM = $(CM:.c=.o)
CB = $(wildcard ft*_bonus.c)
OBB = $(CB:.c=.o)

AR = ar
ARFLM = -rcs
ARFLB = -rcs

UNAME = $(shell uname -s)
ifeq ($(UNAME), Linux)
	VG = valgrind
	VGFL = --leak-check=full --show-leak-kinds=all --track-origins=yes 
endif

all: $(NAME)
$(NAME): $(OBM)
	$(AR) $(ARFLM) $@ $^
bonus: $(OBB)
	$(AR) $(ARFLB) $(NAME) $^
%.o: %.c
	$(CC) $(CCFL) -I$(INCDIR) -c $< -o $@
test_%: all
	$(CC) $(CCFL) -I$(INCDIR) tests/$@.c -l$(LIB) -L$(LIBDIR) && ./a.out
	$(VG) $(VGFL) ./a.out
	rm a.out

re: fclean all
fclean: clean
	rm $(NAME)
clean:
	rm $(OBM) $(OBB)
xclean:
	rm $(NAME)

.PHONY: all bonus clean fclean xclean re
