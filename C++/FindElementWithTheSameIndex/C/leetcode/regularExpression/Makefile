CC = g++
CFLAGS = -g -Wall
OBJS = regExpression.o

regExpression: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o regExpression

$.o: $.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o regExpression


