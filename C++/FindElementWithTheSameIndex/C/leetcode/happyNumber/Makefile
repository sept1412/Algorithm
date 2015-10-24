CC = g++
CFLAGS = -g -Wall
OBJS = happyNumber.o

happyNumber: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o happyNumber

$.o: $.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o happyNumber


