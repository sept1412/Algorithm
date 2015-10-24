CC = clang++
CFLAGS = -std=c++11 -stdlib=libc++ -Weverything
OBJS = anagrams.o

anagrams: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o anagrams

$.o: $.cc
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f *.o anagrams


