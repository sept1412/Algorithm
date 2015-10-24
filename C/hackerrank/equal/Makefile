CC = g++
CFLAGS = -g -Wall
OBJS = equal.o

thief: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o equal

$.o: $.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o equal


