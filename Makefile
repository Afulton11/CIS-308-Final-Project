CC = gcc
OBJS = sodoku.o board.o generator.o random.o unused.o

all: sodoku

sodoku: $(OBJS) sodoku.c
	$(CC) -o sodoku $(OBJS)

clean:
	-rm -f $(OBJS) sodoku 