CC=clang
CFLAGS=-g -Wall

subway: subway-program.c
	$(CC) $(CFLAGS) -o $@ $^
