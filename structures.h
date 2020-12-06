#include <stdlib.h>
#include <stdio.h>

typedef struct l{
  char* premice;
  struct l* next;
} list;

typedef struct{
  list* premices;
  char* conclusion;
}regle;