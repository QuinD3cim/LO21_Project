CC = gcc
CFLAGS =-Werror -pedantic -Wall -std=c99
EXEC = project.exe

all: $(EXEC)

project.exe: fonction.o main.o
	$(CC) -o $@ fonction.o main.o

fonction.o: fonction.c structures.h
	$(CC) -o $@ -c $< $(CFLAGS)

moteur.o: moteur.c
	$(CC) -o $@ -c $< $(CFLAGS)

main.o: main.c moteur.h
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	del *.o $(EXEC)
