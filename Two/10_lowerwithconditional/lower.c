#include <stdio.h>

char lower(char x);
int main(int argc, char** argv)
{
  if( argc != 2 ) {
    printf("Usage: arg 1 = char to be lowercased\n");
    return -1;
  }
  printf("Result: ");
  putchar(lower(argv[1][0]));
  printf("\n");
  return 0;
}

char lower(char x) {
  return (x >= 'A' && x <= 'Z') ? x+'a'-'A' :  x ;
}
