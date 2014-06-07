#include <stdio.h>

/* count blanks, tabs, ad newlines*/
 
main()
{
  int blanks, tabs, newlines, c;
  
  blanks = tabs = newlines = 0;
  while((c = getchar()) != EOF)
    {
      if (c == ' ' || c == '\t')
	{
	  while( (c == ' ')||(c == '\t'))
	    c = getchar();
	    ;
	  putchar(' ');
	}
      putchar(c);

    }
  return 0;
}
