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
  printf("Hello world!\n");
  int index_inbuffer = 0;
  int index_outbuffer = 0;
  int incomment_index = 0;       /* Counters */
  buffer_length = get_buffer(incomingbuffer, TOTALWIDTH);
  char outgoingbuffer[buffer_length];
  int i;
  for(i=0;i<buffer_length;i++) {
    outgoingbuffer[i]='\0';
    printf("int i is: %i\n", i);
  }
  printf("finished array initialization.\n");
  printf("buffer_length is: %i\n", buffer_length);
  for (index_inbuffer=0;index_inbuffer < buffer_length; ++index_inbuffer) {
    printf("index_inbuffer is: %i\n", index_inbuffer);
    if (INCOMMENT && index_inbuffer > 0) {
      if(incomingbuffer[index_inbuffer] == '/' && incomingbuffer[index_inbuffer-1] == '*') {INCOMMENT = 0;}
    } else if (index_inbuffer > 0 && incomingbuffer[index_inbuffer] == '*' && incomingbuffer[index_inbuffer-1] == '/') {
      incomment_index = index_inbuffer;
      while (incomment_index < buffer_length) {
	incomment_index++;
	if (incomingbuffer[incomment_index] == '/' && incomingbuffer[incomment_index-1] == '*') {
	  INCOMMENT = 1;
	  if(index_outbuffer > 0) index_outbuffer--;
	  break;
	}
      }
    } else {
      printf("NOT CORRECT!");
      printf("index_outbuffer: %i\n", index_outbuffer);
      printf("index_inbuffer: %i\n", index_inbuffer);
      outgoingbuffer[index_outbuffer++] = incomingbuffer[index_inbuffer];
      printf("index_outbuffer: %i\n", index_outbuffer);
    }
  }
  printf("buffer_length: %i\n", buffer_length);

  printf("%s\n", outgoingbuffer);
  outgoingbuffer[index_outbuffer] = '\0';
  printf("%s\n", outgoingbuffer);
  return 0;
}



/* get_buffer: read a buffer into s, return length */
int get_buffer(char s[], int lim)
{
  int c, i;
  for (i=0; i<lim-1 && (c=getchar())!= EOF; i++){
    printf("%i\n", i);
    s[i] = c;
  }
  s[i++] = '\0';
  printf("incoming buffer is: %s\n", s);
  printf("incoming buffer length is: %i\n", i);
  return i;
}

