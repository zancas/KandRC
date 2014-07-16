#include <stdio.h>
#include <string.h>

int fbitcount(unsigned i);
int bitcount(unsigned x);
int main(int argc, char** argv)
{
  int BIGCOUNTER = 21474830;
  if (argv[1] == NULL){
    printf("NO!\n");
    return 15;
  }
  if (strcmp(argv[1], "fast") == 0) {
    while (BIGCOUNTER > 0) {
      fbitcount(2147483647);
      BIGCOUNTER--;
    }
  }else if(strcmp(argv[1], "classic") == 0) {
    while (BIGCOUNTER > 0) {
      bitcount(2147483647);
      BIGCOUNTER--;
    }
  }
  printf("bitcount of %d is %d.\n",2147483647, bitcount(2147483647));
  printf("fbitcount of %d is %d.\n",2147483647, fbitcount(2147483647));
  /*printf("bitcount of %d is %d.\n",2147483647, bitcount(2147483647));
  printf("bitcount of %d is %d.\n",8, bitcount(8));
  printf("fbitcount of %d is %d.\n",8, fbitcount(8));
  printf("bitcount of %d is %d.\n",1, bitcount(1));
  printf("fbitcount of %d is2 %d.\n",1, fbitcount(1));
  printf("bitcount of %d is %d.\n",16, bitcount(16));
  printf("fbitcount of %d is %d.\n",16, fbitcount(16));
  printf("bitcount of %d is %d.\n",15, bitcount(15));
  printf("fbitcount of %d is %d.\n",15, fbitcount(15));
  printf("bitcount of %d is %d.\n",32, bitcount(32));
  printf("fbitcount of %d is %d.\n",32, fbitcount(32));
  printf("bitcount of %d is %d.\n",3, bitcount(3));
  printf("fbitcount of %d is %d.\n",3, fbitcount(3));
  */
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
