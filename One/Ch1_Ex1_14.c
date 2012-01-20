#include <stdio.h>

/* counts words and prints a horizontal histogram  */

main()
{
  int MAXCHAR = 256;
  int c, i, j, charcount;
  int num_c;
  int charcounts[MAXCHAR];
  charcount = 0;
  
  for(i = 0; i < MAXCHAR; ++i)
    charcounts[i] = 0;

  while((c = getchar()) != EOF) {
    num_c = c-'\x00';
    printf("%d ", num_c);
    charcounts[num_c]++;
  }

  for(i = 0; i < MAXCHAR; ++i) {
    printf("%3d:", i);
    for (j = 0; j < charcounts[i]; ++j) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
