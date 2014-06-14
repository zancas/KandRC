#include <stdio.h>
#define TOTALWIDTH        80    /* How many columns exist? */       
#define NUMBEROFTABSTOPS  10    /* How many tab stops? */

int get_line(char s[], int lim);
int tabtospace(int position);
char line[TOTALWIDTH];     /* An array that holds the line under process. */
int curr_line_length;      /* Where are we in the line? */


/* Replace tabs with the appropriate number of spaces. */
main()
{
  while((curr_line_length = get_line(line, TOTALWIDTH)) > 0)
    {
      int positioninspaceyline = 0;  /* Keep track of position in the line with spaces.  */
      int i;                 /* Counter */ 
      for (i=0; i < curr_line_length; ++i)
	{
	  if (line[i] == '\t') {
	    positioninspaceyline = tabtospace(positioninspaceyline);
	  }
	  else {
	    positioninspaceyline++;
	    putchar(line[i]);
	  }
	}
    }
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

/* replace tab characters with the appropriate number of spaces */
int tabtospace(int position)
{
  int spacecounter;
  spacecounter = (TOTALWIDTH/NUMBEROFTABSTOPS) - position%(TOTALWIDTH/NUMBEROFTABSTOPS);
  position = position + spacecounter;
  while (spacecounter > 0)
    {
      putchar(' ');
      spacecounter--;
    }
  return position;
}
