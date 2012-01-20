#include <stdio.h>
/* squeeze out all chars in s1 that match any char in s2  */

int rightrot(int i1, int numbits);
int setbits(int i1, int start, int numbits, int i2);

main() 
{
  printf("result: %d\n", rightrot(-2,1));
  return 0;
}



int setbits(int i1, int start, int numbits, int i2) {
  int i2lastnumbits, i1zeroedrightofstart, rightmostbits;
  i2lastnumbits = i2 & ~(~0<<numbits);
  i2lastnumbits <<= start-numbits;
  rightmostbits = i1 & ~(~0<<start-numbits);
  i1zeroedrightofstart = i1 & (~0<<start);
  return i1zeroedrightofstart | i2lastnumbits | rightmostbits;
}


int rightrot(int i1, int numbits) {
  if (i1 < 0) {return -1;}
  int counter = 0;
  int rightshifted = i1 >> numbits;    /* Shift off the rightmost numbitsbits.  */
  int newleftend = i1 & ~(~0<<numbits); /* ... and store them. */
  int shifting = i1;                 
  while (shifting != 0){               /* i1 is counter long */ 
    shifting >>= 1;
    printf("shifting = %d\n", shifting);
    counter++;
  }
  //if (i1 < 0) {counter++;}
  //  rightshifted = rightshifted & ~(~0<<counter); /* make sure left hand bits are zeroed? */
  printf("counter = %d\n", counter);
  printf("rightshifted = %d\n", rightshifted);
  printf("numbits = %d\n", numbits);
  printf("newleftend = %d\n", newleftend);
  return setbits(rightshifted, counter, numbits, newleftend);
}
