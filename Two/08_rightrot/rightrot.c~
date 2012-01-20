#include <stdio.h>
/* squeeze out all chars in s1 that match any char in s2  */

int invertbits(int i1, int start, int numbits);

main() 
{
  printf("result: %d\n", invertbits(15,3,2));
}

int invertbits(int i1, int start, int numbits) {
  int i1fromstartrightnbinv, i1zeroedrightofstart, rightmostbits;
  rightmostbits = i1 & ~(~0<<start-numbits);
  i1zeroedrightofstart = i1 & (~0<<start);
  i1fromstartrightnbinv =  ~((i1 >> start-numbits) | (~0<<numbits)) << start-numbits ;
  return i1zeroedrightofstart | i1fromstartrightnbinv | rightmostbits;
}
