#include <stdio.h>

/* squeeze out all chars in s1 that match any char in s2  */

int setbits(int i1, int start, int numbits, int i2);

main() 
{
  printf("result: %d\n", setbits(15,1,1,16));
}

int setbits(int i1, int start, int numbits, int i2) {
  int i2lastnumbits, i1zeroedrightofstart, rightmostbits;
  i2lastnumbits = i2 & ~(~0<<numbits);
  i2lastnumbits <<= start-numbits;
  rightmostbits = i1 & ~(~0<<start-numbits);
  i1zeroedrightofstart = i1 & (~0<<start);
  return i1zeroedrightofstart | i2lastnumbits | rightmostbits;
}
