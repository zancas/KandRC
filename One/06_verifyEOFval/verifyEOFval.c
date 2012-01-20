#include <stdio.h>

/* verify that EOF is 1 or 0 */
 
main()
{
  int c;
  int boolean;
  while ( boolean = (getchar() != EOF) )
    {
      printf("Value of boolean: %1.0d\n", boolean);
    }
  printf("Value of boolean after the loop has exited: %d\n", boolean);
  return 0;
}
