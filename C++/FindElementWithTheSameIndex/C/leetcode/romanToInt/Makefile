CC = g++
CFLAGS = -g -Wall
OBJS = romanToInt.o

romanToInt: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o romanToInt

$.o: $.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o romanToInt


