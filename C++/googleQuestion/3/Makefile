OBJS = main.o
CC = g++
LFLAGS = -Wall
CFLAGS = -Wall -std=c++11
TARGET = f1Challenge

$(TARGET) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TARGET)

main.o : Car.h Driver.h
	$(CC) $(CFLAGS) -c main.cc

clean:
	rm -rf *.o $(TARGET)

