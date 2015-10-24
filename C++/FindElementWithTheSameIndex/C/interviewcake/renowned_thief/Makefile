CC = g++
CFLAGS = -g -Wall
OBJS = thief.o

thief: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o thief

$.o: $.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o thief

