#include <stdio.h>

main() {
  const int SIZE = 1000;  /* How big is the biggest line we want to process? */
  char line[SIZE];
  int linelength;
  while ((linelength = get_line(line, SIZE)) > 0) {/* We've got a new line! */
    printf("%s", line);
  }
  return 0;
}


/* get_line: read a line into s, return length */
int get_line(char s[], int maximumlength)
{
  int c, i;
  for (i=0; i<maximumlength-1 ; ++i) {
    if ((c = getchar())!=EOF) {
      if (c!='\n') {
	s[i] = c;
      } else if ( c == '\n') { break; }
    } else if (c == EOF) { break; }
  }
  if (c == '\n') {
    s[i] = c;
    ++i;
  }
  s[i] = '\0';
  return i;
}
