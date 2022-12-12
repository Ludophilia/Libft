# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jgermany <nyaritakunai@outlook.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/30 13:02:44 by jgermany          #+#    #+#              #
#    Updated: 2022/12/12 20:37:00 by jgermany         ###   ########.fr        #
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
CFILES = $(wildcard /ft*.c) #SIR, WHERE ARE YOUR MANDATORY C FILES ??
# LEARN TO USE GLOB PATTERN MATCHING, OR WRITE EVERY NAME (LOL)
# AND HOW 'BOUT THE BONUSES? I THOUGHT WE WERE VERY CLEAR ON THAT!!
OBFILES = $(CFILES:.c=.o)

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
