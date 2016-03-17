CC = g++
LFLAGS = -o
CFLAGS = -c

OBJS = main.o

main: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) main

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

