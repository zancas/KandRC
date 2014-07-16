#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int fbitcount(unsigned i);
int bitcount(unsigned x);
int main(int argc, char** argv)
{
  if( argc != 3 ) {
    printf("Usage: arg 1 = {classic,fast}, arg 2 = n: integer whose bits will be counted\n");
    return -1;
  }
  int BIGCOUNTER = 21474830;
  if (strcmp(argv[1], "fast") == 0) {
    while (BIGCOUNTER > 0) {
      fbitcount(atoi(argv[2]));
      BIGCOUNTER--;
    }
  }else if(strcmp(argv[1], "classic") == 0) {
    while (BIGCOUNTER > 0) {
      bitcount(atoi(argv[2]));
      BIGCOUNTER--;
    }
  }
  return 0;
}


int fbitcount(unsigned i) {
  int bc;
  if (i == 0) {return 0;}
  for(bc=1; (i&=(i-1)) != 0; bc++ ) {
    ;
  }
  return bc;
}

int bitcount(unsigned x) {
  int b;
  for (b = 0; x != 0; x>>=1) {
    if (x & 01) {
      b++;
    }
  }
  return b;
}
