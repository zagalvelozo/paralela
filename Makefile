CC=gcc
all: build
build: 
      $(CC) main.c -o main
run:
     ./main
clean:
      rm -rf *.o
