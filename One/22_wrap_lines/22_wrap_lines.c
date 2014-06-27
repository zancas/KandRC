#include <stdio.h>
#define FOLDWIDTH        120    /* How many columns exist? */       
#define INBUFFERSIZE  100000    /* How long can a line be? */

/* The fundamental procedure is that the beginning of the input line is read into a FOLDWITH length buffer.  The buffer is then rightstripped of whitespace, and printf'd.  This process is iterated until the input buffer is empty. */

int get_line(char s[], int lim);   /* Get a line from standard in. */
void rightstripwhitespace(char inputline[], int length);  /* Replace trailing ws with '\0'. */
void initialize_buffer(char raw_buffer[], int buffer_length);
char long_line[INBUFFERSIZE];  /* A big array that holds up to INBUFFERSIZE input */
char line[FOLDWIDTH];          /* An array that holds the line under process. */
int long_line_length;               /* Where are we in the line? */


/* Fold long lines into a seris of FOLDWIDTH - trailing whitespace lines. */
main()
{
  int i, index_in_line;                 /* Counter */
  long_line_length = get_line(long_line, INBUFFERSIZE);
  for (i=0; i < long_line_length; ++i) {
    index_in_line = i%FOLDWIDTH;
    line[index_in_line] = long_line[i];/* Fill up the buffer of chars for the last line. */
    if (i%FOLDWIDTH == FOLDWIDTH-1) { 
      /* Check to see if a tabstop is bounded by at least two spaces.  */
      printf("%s\n",line);
      initialize_buffer(line, FOLDWIDTH);
    }
  }
  printf("%s", line); /* Print the last column processed for the line, for short lines this is the first column.  */
}

void initialize_buffer(char raw_buffer[], int buffer_length)
{
  int j;
  for (j = 0 ; j < buffer_length; j++) { /* Initialize last_tw_chars to deal with short line edge case.*/
    raw_buffer[j] = '\0';
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

/* Will replaces characters between terminal nonw and length with '\0'. */
void rightstripwhitespace(char inputline[], int length) {
  int indexofnonw, j;  
  /* Find the index of the first character not '\t' or ' ' from the end. */
  for (indexofnonw = length-1; 
       indexofnonw > 0 && (inputline[indexofnonw] == ' ' || inputline[indexofnonw] == '\t' || inputline[indexofnonw] == '\n' || inputline[indexofnonw] == '\0');
       --indexofnonw)
    ;
  /* Replace everything from terminal non-white to length with '\0'.  */
  for (j=indexofnonw; j<length; ++j)
    {
      inputline[j] = '\0';
    }
}
