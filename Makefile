CC = gcc
CFLAGS =-Werror -pedantic -Wall -std=c99
EXEC = project.exe

project.exe: fonction.o main.o
	$(CC) -o $@ $^
fonction.o: fonction.c structures.h
	$(CC) -o $@ -c $< $(CFLAGS)
project.o: main.c fonction.h
	$(CC) -o $@ -c $< $(CFLAGS)


