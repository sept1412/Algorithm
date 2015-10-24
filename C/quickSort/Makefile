CC = g++
CFLAGS = -g -Wall
OBJS = quickSort.o

quickSort: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o quickSort

$.o: $.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o quickSort


