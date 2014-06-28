#include <stdio.h>
#define TOTALWIDTH 100000  /* Max size of the input buffer. */
int INCOMMENT = 0;

// MAKE THIS A FUNCTION TO USE IN 24.

/* The fundamental procedure is that comment beginning '/*''s are used to
   indicate comment entry. Comment state is recorded with an INCOMMENT
   boolean flag. putchar is not called while INCOMMENT is 1 */

int get_buffer(char s[], int lim);
char incomingbuffer[TOTALWIDTH];     /* An array that holds the buffer under process. */
int buffer_length;      /* Where are we in the buffer? */

//FOOTBALLFOOLBOOF
/* Replace spaces with with the appropriate number of tabs. */
main()
{
  int slash_slash = 0;
  int index_inbuffer = 0;
  int index_outbuffer = 0;
  int incomment_index = 0;       /* Counters */
  buffer_length = get_buffer(incomingbuffer, TOTALWIDTH);
  char outgoingbuffer[buffer_length];
  int i;
  for(i=0;i<buffer_length;i++) {
    outgoingbuffer[i]='\0';
  }//ANOTHER COMMENT
  for (index_inbuffer=0;index_inbuffer < buffer_length; ++index_inbuffer) {
    if (INCOMMENT) {
      if(slash_slash) {
	if(incomingbuffer[index_inbuffer] == '\n') {
	  INCOMMENT = 0;
	  slash_slash = 0;
	  outgoingbuffer[index_outbuffer++] = '\n';
	}/*Also this/* // */
      }
      if(incomingbuffer[index_inbuffer] == '/' && incomingbuffer[index_inbuffer-1] == '*') {INCOMMENT = 0;}
    } else if (index_inbuffer > 0 && incomingbuffer[index_inbuffer] == '*' && incomingbuffer[index_inbuffer-1] == '/') {
      incomment_index = index_inbuffer;
      while (incomment_index < buffer_length) {
	incomment_index++;
	if (incomingbuffer[incomment_index] == '/' && incomingbuffer[incomment_index-1] == '*') {
	  INCOMMENT = 1;
	  index_outbuffer--;
	  break;
	}
      }
      if(!INCOMMENT) {
	outgoingbuffer[index_outbuffer++] = incomingbuffer[index_inbuffer];
      }
    } else if (index_inbuffer > 0 && incomingbuffer[index_inbuffer] == '/' && incomingbuffer[index_inbuffer-1] == '/') {
      slash_slash = 1;
      INCOMMENT = 1;
      index_outbuffer--;
    } else {
      outgoingbuffer[index_outbuffer++] = incomingbuffer[index_inbuffer];
    }
  }
  outgoingbuffer[index_outbuffer] = '\0';
  printf("%s", outgoingbuffer);
  return 0;
}



/* get_buffer: read a buffer into s, return length */
int get_buffer(char s[], int lim)
{
  int c, i;
  for (i=0; i<lim-1 && (c=getchar())!= EOF; i++){
    s[i] = c;
  }
  s[i++] = '\0';
  return i;
}

