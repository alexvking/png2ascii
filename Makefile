CC = gcc
CFLAGS = -Wall -Werror -O3
OBJS = png2ascii.o lodepng.o

all: png2ascii

default: png2ascii

png2ascii: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o png2ascii

png2ascii.o: png2ascii.c
	$(CC) $(CFLAGS) -c png2ascii.c

lodepng.o: lodepng.c lodepng.h
	$(CC) $(CFLAGS) -c lodepng.c

clean:
	rm -f *~ *.o png2ascii