# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 13:02:44 by jgermany          #+#    #+#              #
#    Updated: 2022/12/21 22:09:27 by jgermany         ###   ########.fr        #
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
ARFLB = -qs

VG = valgrind
VGFL = --leak-check=full --show-leak-kinds=all --track-origins=yes 

all: $(NAME)
$(NAME): $(OBM)
	$(AR) $(ARFLM) $@ $^
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

bonus: $(NAME) $(OBB)
	$(AR) $(ARFLB) $^

.PHONY: all clean fclean xclean re bonus test_%
