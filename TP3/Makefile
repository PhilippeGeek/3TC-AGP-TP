CC = gcc
CFLAGS = -Wall

pile.o: pile.c
	$(CC) $(CFLAGS) -c pile.c -o pile.o

hanoi.o: hanoi.c hanoi.h pile_type.h
	-$(CC) $(CFLAGS) -c hanoi.c -o hanoi.o

hanoi: pile.o hanoi.o
	-$(CC) $(CFLAGS) -o hanoi hanoi.o pile.o