#include <stdio.h>

/* counts words and prints a horizontal histogram  */

#define IN  1             /*inside a word*/
#define OUT 0             /*outside a word*/
main()
{
  int MAXWORDLENGTH = 20;
  int c, i, j, state, wordlength, maxobserved;
  int wordlengths[MAXWORDLENGTH];
  wordlength = maxobserved = 0;
  
  for(i = 0; i < MAXWORDLENGTH; ++i)
    wordlengths[i] = 0;

  state = OUT;
  while((c = getchar()) != EOF) {
    if (c == ' ' || c == '\n' || c == '\t') {
      state = OUT;
      wordlengths[wordlength]++;
      wordlength = 0;
    }
    else if (state == OUT) {
      wordlength++;
      state = IN;
    }
    else {
      wordlength++;
    }
  }
  for(i = 0; i < MAXWORDLENGTH; ++i) {
    printf("%2d:", i);
    for (j = 0; j < wordlengths[i]; ++j) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
