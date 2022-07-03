CC=gcc
all: build
build: 
	$(CC) main.c -o main
clean:
	rm -rf *.o
