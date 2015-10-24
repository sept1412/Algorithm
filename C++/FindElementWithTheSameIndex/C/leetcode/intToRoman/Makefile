CC = g++
CFLAGS = -g -Wall
OBJS = intToRoman.o

intToRoman: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o intToRoman

$.o: $.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o intToRoman


