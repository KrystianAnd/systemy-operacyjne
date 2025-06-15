CC=gcc
AR=ar rcs
CFLAGS=-Wall -g

all: menedzer pracownik glowny

menedzer:
	$(CC) $(CFLAGS) -c manager.c
	$(AR) libmanager.a manager.o

pracownik:
	$(CC) $(CFLAGS) -c worker.c
	$(AR) libworker.a worker.o

glowny: main.c libmanager.a libworker.a
	$(CC) $(CFLAGS) main.c -L. -lmanager -lworker -o projekt

clean:
	rm -f *.o *.a projekt