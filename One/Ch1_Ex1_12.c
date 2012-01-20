#include <stdio.h>

#define IN 1    /*Inside a word*/
#define OUT 0    /*Outside a word*/

/* Count lines, words, and characters in input */
 
main()
{
  int c, state;
  int NEWLINE = '\n';

  state = OUT;
  while((c = getchar()) != EOF) {
    if (c == '\n') {
      putchar(c);
    }
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
    }
    else if (state == OUT) {
      putchar(NEWLINE);
      putchar(c);
      state = IN;
    }
    else {
      putchar(c);
    }
  }
  return 0;
}
