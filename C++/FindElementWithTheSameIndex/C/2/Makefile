C=gcc
CFLAGS=
DEPS = 2.h

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
2: 2.o
	gcc -o 2 2.o

clean:
	rm -f *.o 2
