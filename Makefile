CFLAGS=-g -Wall -std=c11
LDLIBS=-lm

all: euler

clean :
	rm -f *.o *~ euler
