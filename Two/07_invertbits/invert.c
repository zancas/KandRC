#include <stdio.h>
#include <stdlib.h>
/* for x invert n bits beginning p from right*/

int invert_n_bits_at_p(int x, int n, int p);
int build_selector(int p, int n);

int main(int argc, char** argv)
{
  if( argc != 4 ) {
    printf("Usage: arg 1 = x, arg 2 = n, arg 3 = p: for x invert n bits beginning at p from right\n");
    return -1;
  }
  printf("result: %d\n", invert_n_bits_at_p(atoi(argv[1]),atoi(argv[2]),atoi(argv[3])));
}

int invert_n_bits_at_p(int x, int p, int n) {
  int selector = build_selector(p, n);
  int x_inv = ~x;
  int target_segment = x_inv & selector;
  x = x & ~selector;
  x = x | target_segment;
  printf("result: %d\n", x);
  //printf("selector: %d\n", selector);
  return 0;
}

int build_selector(int p, int n){
  int selector = 0;
  int leader = p;
  int size = n;
  while (p>=0){
    p--;
    selector <<= 1;
    if (n>0){
      n--;
      selector++;
    }
    printf("selector: %d\n", selector);
  }
  return selector;
}


