#include <stdio.h>
#define TOTALWIDTH 100000  /* Max size of the input buffer. */
int INCOMMENT = 0;

/* The fundamental procedure is that comment beginning '/*''s are used to
   indicate comment entry. Comment state is recorded with an INCOMMENT
   boolean flag. putchar is not called while INCOMMENT is 1 */

int get_buffer(char s[], int lim);
char incomingbuffer[TOTALWIDTH];     /* An array that holds the buffer under process. */
int buffer_length;      /* Where are we in the buffer? */


/* Replace spaces with with the appropriate number of tabs. */
main()
{
  int index_inbuffer, index_outbuffer;       /* Counters */
  buffer_length = get_buffer(incomingbuffer, TOTALWIDTH);
  char outgoingbuffer[buffer_length];
  for (index_inbuffer=0; index_inbuffer < buffer_length; ++index_inbuffer) {
    if (INCOMMENT) {
      if(incomingbuffer[index_inbuffer] == '/' && incomingbuffer[index_inbuffer-1] == '*') {INCOMMENT = 0;} 
    } else if (incomingbuffer[index_inbuffer] == '*' && incomingbuffer[index_inbuffer-1] == '/') {
      INCOMMENT = 1;
      index_outbuffer--;
    } else {
      outgoingbuffer[index_outbuffer] = incomingbuffer[index_inbuffer];
      index_outbuffer++;
    }
  }
  index_outbuffer++;
  outgoingbuffer[index_outbuffer] = '\0';
  printf("%s", outgoingbuffer);
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

