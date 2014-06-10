#include <stdio.h>

// counts chars and prints a vertical ascii-character frequency histogram

main()
{
  int MAXCHAR = 128;
  int c, i, j, charcount;
  int charcounts[MAXCHAR];
  for(i = 0; i < MAXCHAR; ++i){charcounts[i] = 0;}
  charcount = 0;

  while((c = getchar()) != EOF) {
    charcounts[c]++;
  }
  for(i = 0; i < MAXCHAR; ++i) {
    if(charcounts[i] == 0){continue;}
    for (j = 0; j < charcounts[i]; ++j) {
      printf("*");
    }
    printf("\n");
  }
  return 0;
}
