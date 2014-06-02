#include <stdio.h>

/* count blanks, tabs, ad newlines*/

main()
{
  int blanks, tabs, newlines, c;

  blanks = tabs = newlines = 0;
  while((c = getchar()) != EOF)
    {
      if (c == ' '){blanks=blanks+1;}
      else if (c == '\t'){tabs=tabs+1;}
      else if (c == '\n'){newlines=newlines+1;}
    }
  printf("number of blanks %d.\n", blanks);
  printf("number of tabs %d.\n", tabs);
  printf("number of newlines %d.\n", newlines);
  return 0;
}
