#! /bin/bash

NAME='x00'

CC='cc'
CFLAGS='-Wall -Wextra -Werror'

FT_DIR='../../..'

SRCS='main.c'

if [ $# -eq 0 ] || ([ $# -eq 1 ] && [ $1 = 'all' ]); then
	make -s -C $FT_DIR all
	$CC $CFLAGS -I$FT_DIR -o $NAME $SRCS -lft -L$FT_DIR
elif ([ $# -eq 1 ] && [ $1 = 'fclean' ]); then
	make -s -C $FT_DIR fclean
	rm -rf $NAME
fi
