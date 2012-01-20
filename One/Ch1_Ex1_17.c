#include <stdio.h>
#define MAXLINE 1000   /* maximum input line size */

int get_line(char line[], int maxline);

/* print right stripped input line */
main()
{
  int len;                 /* current line length*/
  char line[MAXLINE];      /* current input line */
  int indexofnonw, j;
  
  while ((len = get_line(line, MAXLINE)) > 0)
    {
      // Find the index of the first character not '\t' or ' ' from the end.
      for (indexofnonw = len; line[indexofnonw] != ' ' && line[indexofnonw] != '\t'  ; --indexofnonw )
	;
      if (indexofnonw!=0)
	{
	  char toprint[indexofnonw+1]; 
	  for (j=0; j<indexofnonw; ++j)
	    {
	      toprint[j] = line[j];
	    }
	  j++;
	  toprint[j] = '\0';
	  printf("Right Stripped: %s\n", toprint);
	}
    }
  return 0;
}

/* get_line: read a line into s, return length */
int get_line(char s[], int lim)
{
  int c, i;
  
  for (i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
    s[i] = c;
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
