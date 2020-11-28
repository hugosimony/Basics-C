# Makefile

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -O0 -g
MATHS = maths.c

all: clean maths

maths :
	${CC} ${MATHS} ${CFLAGS} -o maths

clean :
	${RM} arrays maths

# END