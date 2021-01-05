CC = gcc
CFLAGS =-Werror -pedantic -g -ansi -Wall -std=c99
EXEC = project.exe

all: $(EXEC)

project.exe: moteur.o main.o fonction.o
	$(CC) -o $@ $^

moteur.o: moteur.c fonction.h
	$(CC) -o $@ -c $< $(CFLAGS)

fonction.o: fonction.c structures.h
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.c moteur.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	del *.o $(EXEC)
