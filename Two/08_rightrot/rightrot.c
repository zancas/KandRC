#include <stdio.h>
#include <stdlib.h>
/* rotate x to the right by n bits */

int rightrot(int x, int n);

int main(int argc, char** argv)
{
  if( argc != 3 ) {
    printf("Usage: arg 1 = x, arg 2 = n: rotate x to the right by n bits\n");
    return -1;
  }
  printf("result: %d\n", rightrot(atoi(argv[1]), atoi(argv[2])));
  return 0;
}

int rightrot(int x, int n) {
    int selector = 0;
    int n_count = n;
    while(n_count > 0){
      n_count--;
      selector <<= 1;
      selector++;
    }
    selector = selector & x;
    selector <<= (32-n);
    x = x >> n;
    x = x|selector;
    return x;
}
