#include <stdio.h>
#define TOTALWIDTH        80    /* How many columns exist? */       
#define NUMBEROFTABSTOPS  10    /* How many tab stops? */

/* The fundamental procedure is that a spaceset that bounds a tabstop, from the left,
   causes spacetotab to be called. In the edge case where there is a single space
   bounding a tabstop spacetotab is not called on the assumption that coincidental
   spaces are more common than one-space tabs. */

int get_line(char s[], int lim);
void spacetotab(char last_column[], int incolumnpos);   /* Returns 'int' signal appropriate for modification of index in line parsing loop.
				A tab has replaced two or more space characters and the position must be decremented
				accordingly. */
void initialize_column(char last_column[], int colwidth);
char line[TOTALWIDTH];     /* An array that holds the line under process. */
int curr_line_length;      /* Where are we in the line? */


/* Replace spaces with with the appropriate number of tabs. */
main()
{
  int TABWIDTH = TOTALWIDTH/NUMBEROFTABSTOPS;  /* How wide */
  char last_tw_chars[TABWIDTH+1];    /* Array that stores chars back to the last tabstop. Plus a terminal \0 */
  initialize_column(last_tw_chars, TABWIDTH+1);
  int i;                 /* Counter */
  int index_in_last_col; /* Index being modified in last_tw_chars  */
  while((curr_line_length = get_line(line, TOTALWIDTH)) > 0)
    {
      for (i=0; i < curr_line_length; ++i) {
	index_in_last_col = i%TABWIDTH;
	last_tw_chars[index_in_last_col] = line[i];/* Fill up the buffer of chars for the last column. */
	if (i%TABWIDTH == 7 && last_tw_chars[TABWIDTH-1] == ' ' && last_tw_chars[TABWIDTH-2] == ' ') { 
	  /* Check to see if a tabstop is bounded by at least two spaces.  */
	  spacetotab(last_tw_chars, TABWIDTH);
	}
	if (i%TABWIDTH == 7) {
	  /* Print out last column (whether or not it was modified */
	  printf("%s", last_tw_chars);
	  initialize_column(last_tw_chars, TABWIDTH+1);
	}
      }
      printf("%s", last_tw_chars); /* Print the last column processed for the line, for short lines this is the first column.  */
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
void spacetotab(char last_column[], int incolumnpos)
{
  while (incolumnpos >= 0 && (last_column[incolumnpos] == '\0' || last_column[incolumnpos] == ' '))
    { incolumnpos--; }
  if (incolumnpos != -1) {
    last_column[incolumnpos+1] = '\t';
    last_column[incolumnpos+2] = '\0';
  }else {/* There are only spaces in the preceding column  */
    last_column[0] = '\t';
    last_column[1] = '\0';
  }
}

void initialize_column(char last_column[], int colwidth)
{
  int j;
  for (j = 0 ; j < colwidth; j++) { /* Initialize last_tw_chars to deal with short line edge case.*/
    last_column[j] = '\0';
  }  
}
