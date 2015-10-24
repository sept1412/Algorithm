CC=gcc
CFLAGS=
DEPS = 1.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
1: 1.o
	gcc -o 1 1.o

clean:
	rm -f *.o 1
