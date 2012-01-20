#include <stdio.h>
#define MAXLINE 1000   /* maximum input line size */

int get_line(char line[], int maxline);
void reverse(char s[], int lim);

/* print reversed input line */
main()
{
  int len;                 /* current line length */
  char line[MAXLINE];      /* current input line  */
  int indexofnonw, j;
  
  while ((len = get_line(line, MAXLINE)) > 0)
    {
      reverse(line, len);
    }
  printf("\n");
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

/* reverse: takes a char array s[] and putchars its reverse */
void reverse(char s[], int lim)
{
  int j;
  for (j = lim; j>=0 ; --j)
    {
      putchar(s[j]);
    }
}
