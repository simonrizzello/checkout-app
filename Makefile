CC = g++
LFLAGS = -o
CFLAGS = -c -std=c++11

OBJS = main.o Checkout.o

main: $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) main

main.o : main.cpp
	$(CC) $(CFLAGS) main.cpp

Checkout.o: Checkout.cpp Checkout.h
	$(CC) $(CFLAGS) Checkout.cpp

