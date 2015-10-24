CC = g++
CFLAGS = -g -Wall
OBJS = inorderBST.o

thief: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o inorderBST

$.o: $.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o inorderBST


