AR = ar
AFLAGS = rcs
CC = gcc
LIBS = libString.a
OBJS = sodoku.o board.o

all: sodoku

sodoku: $(OBJS) $(LIBOBJS) sodoku.c
	$(CC) -o sodoku $(OBJS)

clean:
	-rm -f $(OBJS) sodoku 