CC = g++
CFLAGS = -g -Wall
OBJS = serializeBST.o

serializeBST: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o serializeBST

$.o: $.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o serializeBST


