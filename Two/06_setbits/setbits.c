#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

/* return i1 with the numbits that begin at start replaced with the rightmost numbits from i2  */

int setbits(int i1, int start, int numbits, int i2);

int main(int argc, char** argv)
{
  if(argc != 5){
    printf("You must pass 4 ints to this function:\n");
    printf("The first value will have a number of bits 'numbits' specified by the third,");
    printf(" starting at the offset specified in the second,");
    printf(" replaced by the rightmost 'numbits' of the fourth.\n");
    return -1;
  }
  printf("result: %d\n", setbits(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4])));
}

int setbits(int i1, int start, int numbits, int i2) {
  int i2lastnumbits, i1zeroedrightofstart, rightmostbits;
  printf("INT_MAX: %d\n", INT_MAX);
  printf("INT_MIN: %d\n", INT_MIN);
  double bits = 0;
  int MAX = INT_MAX;
  while(MAX!=0){
    bits++;
    MAX = MAX<<1;
  }
  printf("i1: %d\n", i1);
  i1zeroedrightofstart = i1 & ((int)pow(2.0,bits)<<start);
  printf("i1zeroedrightofstart: %d\n", i1zeroedrightofstart);
  printf("i2: %d\n", i2);
  i2lastnumbits = i2 & ~((int)pow(2.0,bits-1)<<numbits);
  printf("i2lastnumbits: %d\n", i2lastnumbits);
  i2lastnumbits <<= (int)bits-(start+numbits);
  printf("i2lastnumbits: %d\n", i2lastnumbits);
  rightmostbits = i1 & ~((int)pow(2.0, bits-1)<<((int)bits-(start+numbits)));
  printf("rightmostbits: %d\n", rightmostbits);
  i1 <<= 1;
  printf("i1: %d\n", i1);
  printf("9/8: %d\n", 9/8);
  return i1zeroedrightofstart | i2lastnumbits | rightmostbits;
}
