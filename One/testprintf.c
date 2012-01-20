#include <stdio.h>
char printable[3];

main()
{
  printable[0] = '\t';
  printable[1] = 'a';
  printable[2] = '\0';
  printf("%s\n", printable);
}
