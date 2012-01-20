#include <stdio.h>

int lower(int x);
main() 
{
  
  putchar(lower('x'));
  return 0;
}

int lower(int x) {
  int temp;
  temp = (x >= 'A' && x <= 'Z') ? x+'a'-'A' :  x ;
  return temp;
}
