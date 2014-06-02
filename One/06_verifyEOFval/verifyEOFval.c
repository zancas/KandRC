#include <stdio.h>

/* verify that getchar() != EOF is 1 or 0 */

main()
{
  int c;
  int boolean;
  while ( boolean = ((c = getchar()) != EOF) )
    {
      printf("Value of boolean: %1.0d\n", boolean);
      printf("c: %c\n", c);
      printf("c: %d\n", c);
      printf("----\n");
    }
  printf("Value of boolean after the loop has exited: %d\n", boolean);
  printf("Numeric value of c after the loop has exited: %d\n", c);
  printf("Character repr of c after the loop has exited: %c\n", c);
  printf("Character repr of c after the loop has exited: %x\n", c);
  return 0;
}
