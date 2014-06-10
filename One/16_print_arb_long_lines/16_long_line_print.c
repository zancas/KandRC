#include <stdio.h>
#define MAXLINE 1000   /* maximum input line size */

int get_line(void);
int c, length = 0;
/* print longest input line */
main()
{
  c = getchar();
  if (c != EOF){
    putchar(c);
    length++;
    while (c != EOF)
      {
	length = length + get_line();
	printf("\nThat line was %d chars long!\n", length);
	c = getchar();
	if (c !=EOF)
	  {
	    putchar(c);
	  }
	length = 1;
      }
  }
  return 0;
}

/* get_line: read a line into s, return length */
int get_line()
{
  int len = 0;
  int c = getchar();
  while (c != '\n' && c != EOF)
    {
      putchar(c);
      len++;
      c = getchar();
    }
  return len;
}
