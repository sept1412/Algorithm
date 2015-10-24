CC = g++
CFLAGS = -g -Wall
OBJS = missingValue.o

missingValue: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o missingValue

$.o: $.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o missingValue


