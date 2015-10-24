CC = g++
CFLAGS = -g -Wall
OBJS = numberOf1Bits.o

numberOf1Bits: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o numberOf1Bits

$.o: $.cpp
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o numberOf1Bits


