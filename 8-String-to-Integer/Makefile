CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

all: static shared

static:
	$(CC) -c src/lsatoi.c $(CFLAGS) -o lsatoi.o
	ar rcs liblsatoi.a lsatoi.o

shared:
	$(CC) -fPIC -c src/lsatoi.c $(CFLAGS)
	$(CC) -shared -o liblsatoi.so lsatoi.o

clean:
	rm -f *.o *.a *.so

