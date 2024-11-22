#! /bin/bash

NAME='x26'

CC='cc'
CFLAGS='-Wall -Wextra -Werror -g3'

# unset CFLAGS

FT_DIR='../../..'

MKFLAGS="-C $FT_DIR"
if [ $# -eq 1 ] && [ $1 = '-s' ]; then
	MFLAGS+=' -s'
fi

SRCS='main.c'

if [ $# -eq 0 ] || ([ $# -eq 1 ] && [ $1 = 'all' ]); then
	make -s $MKFLAGS all
	$CC $CFLAGS -I$FT_DIR -o $NAME $SRCS -lft -L$FT_DIR -lbsd
elif ([ $# -eq 1 ] && [ $1 = 'fclean' ]); then
	make -s -C $FT_DIR fclean
	rm -rf $NAME
fi
