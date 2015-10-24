CC = g++
CFLAGS = -g -Wall
OBJS = houseRobber.o

houseRobber: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o houseRobber

$.o: $.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o houseRobber


