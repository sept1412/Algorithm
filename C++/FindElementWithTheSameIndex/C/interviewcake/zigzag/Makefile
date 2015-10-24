CC = g++
CFLAGS = -g -Wall
OBJS = zigzag.o

thief: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o zigzag

$.o: $.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o zigzag


