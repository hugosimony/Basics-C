# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O0 -g
ARRAYS = arrays.c
MATHS = maths.c

all: clean arrays maths

arrays :
	${CC} ${ARRAYS} ${CFLAGS} -o arrays
	${CC} ${MATHS} ${CFLAGS} -o maths

clean :
	${RM} arrays maths

# END