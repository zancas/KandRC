#include <stdio.h>
#define TOTALWIDTH 100000  /* Max size of the input buffer. */


/* COMMENTS:  Obviously characters inside comments are not handled as part of the C
   syntax, therefore we ignore them in the following way:
   The procedure is that comment beginning '/*''s are used to
   indicate comment entry. Comment state is recorded with an incomment
   boolean flag. chars are not parsed while incomment is 1 */

/* BALANCING:  How are we to know if characters-that-require-balance are unbalanced?
   This can happen in two ways:
      -- 1:  The number of termination characters is greater than the number of initiator
      characters.
      -- 2:  The number of initiator characters is greater than the number of terminator
      characters.

      To account for '1' simply subtract 1 from the initiator count every time a terminator
      is encountered.
      *  If the number of initiators drops below 0, the code is unbalanced
      To account for '2', at the end of the buffer, count the number of initiators (after the 
      above accounting).
      *  If the number of iniators is not 0 (it must be > since we already checked for <), 
      then the code is unbalanced. */

int get_buffer(char s[], int lim);
char incomingbuffer[TOTALWIDTH];     /* An array that holds the buffer under process. */
int buffer_length;      /* Where are we in the buffer? */
int squiggle_opens = 0;
int paren_opens = 0;
int brace_opens = 0;
int doublequotes = 0;
int singlequotes = 0;
int incomment = 0;

/* Replace spaces with with the appropriate number of tabs. */
main()
{
  int index_inbuffer;       /* Counters */
  buffer_length = get_buffer(incomingbuffer, TOTALWIDTH);
  for (index_inbuffer=0; index_inbuffer < buffer_length; ++index_inbuffer) {
    if (incomment) {   
      /* If syntax correct we're in a comment. */
      if(incomingbuffer[index_inbuffer] == '/' && incomingbuffer[index_inbuffer-1] == '*') {incomment = 0;} 
    } else if (incomingbuffer[index_inbuffer] == '*' && incomingbuffer[index_inbuffer-1] == '/') {
      incomment = 1;      
    } else if (doublequotes%2 == 1) { 
      /* If syntax correct, we're inside double quotes. */
      if(incomingbuffer[index_inbuffer] == '"' && incomingbuffer[index_inbuffer-1] != '\\') {doublequotes++;} 
    } else if (incomingbuffer[index_inbuffer] == '"' && incomingbuffer[index_inbuffer-1] != '\\') {
      doublequotes++;      
    } else if (singlequotes%2 == 1) { 
      /* If syntax correct, we're inside single quotes. */
      if(incomingbuffer[index_inbuffer] == '\'' && incomingbuffer[index_inbuffer-1] != '\\') {singlequotes++;} 
    } else if (incomingbuffer[index_inbuffer] == '\'' && incomingbuffer[index_inbuffer-1] != '\\') {
      singlequotes++;      
    } else if (incomingbuffer[index_inbuffer] == '{' && incomingbuffer[index_inbuffer-1] != '\\') {
      /* If syntax correct we're inside squiggles. */
      squiggle_opens++;
    } else if (incomingbuffer[index_inbuffer] == '}' && incomingbuffer[index_inbuffer-1] != '\\') {
      squiggle_opens--;
    } else if (incomingbuffer[index_inbuffer] == '(' && incomingbuffer[index_inbuffer-1] != '\\') {
      /* If syntax correct we're inside parens. */
      paren_opens++;
    } else if (incomingbuffer[index_inbuffer] == ')' && incomingbuffer[index_inbuffer-1] != '\\') {
      paren_opens--;
    } else if (incomingbuffer[index_inbuffer] == '[' && incomingbuffer[index_inbuffer-1] != '\\') {
      /* If syntax correct we're inside braces. */
      brace_opens++;
    } else if (incomingbuffer[index_inbuffer] == ']' && incomingbuffer[index_inbuffer-1] != '\\') {
      brace_opens--;
    }
    /* If test to see if we already know about a syntax error. */
    if (squiggle_opens < 0) {return 1;}
    if (paren_opens < 0) {return 2;}
    if (brace_opens < 0) {return 3;}
  }
  
  if (squiggle_opens != 0) {
    printf("The were %d squiggle_opens after processing finished.\n", squiggle_opens);
    return 4;
  }
  if (paren_opens != 0) {
    printf("The were %d paren_opens after processing finished.\n", paren_opens);
    return 5;
  }
  if (brace_opens != 0) {
    printf("The were %d brace_opens after processing finished.\n", brace_opens);
    return 6;
  }
  if (incomment) {
    return 7;
  }
  if (doublequotes%2 == 1) {
    return 8;
  }
  if (singlequotes%2 == 1) {
    return 9;
  }
  return 0;
}



/* get_buffer: read a buffer into s, return length */
int get_buffer(char s[], int lim)
{
  int c, i;
  for (i=0; i<lim-1 && (c=getchar())!= EOF; i++)
    s[i] = c;
  s[i] = '\0';
  return i;
}
