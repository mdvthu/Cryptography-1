# Macros:
# compiler command
CC=gcc
# compiler flags
CFLAGS=Wall
# the name of the binary
BINNAME=crypto1


all:
	$(CC) -$(CFLAGS) main.c functions.c -o $(BINNAME)
debug:
	$(CC) -$(CFLAGS) main.c functions.c -o $(BINNAME) -DDEBUG
clean:
	rm -f *.o $(BINNAME)

