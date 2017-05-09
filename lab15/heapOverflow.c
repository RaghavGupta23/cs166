#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main() {
  int diff, size = 8;
  char *buff1, *buff2;
  buff1 = (char*) malloc(size);
  buff2 = (char*) malloc(size);
  diff = buff2 - buff1;
  memset(buff2, '2', size);
  printf("BEFORE: buff2 = %s \n", buff2);
  memset(buff1, '1', diff + 3);
  printf("AFTER:  buff2 = %s \n", buff2);
}

