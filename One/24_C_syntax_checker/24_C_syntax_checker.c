#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* COMMENTS:  Comments are excised using the comment excision program from exerise 23.  To also handle
      '//' type comments that code will be extended.*/

char* read_file_chars_into_heap_array(char* filename, char* heap_chars);
char* excise_comments(char* code_array, char* excised_array);

char* excise_comments(char* code_array, char* excised_array){
  int buffer_length = 0;
  int INCOMMENT = 0;
  int slash_slash = 0;
  int index_inbuffer = 0;
  int index_outbuffer = 0;
  int incomment_index = 0;       /* Counters */
  buffer_length = strlen(code_array);
  excised_array = realloc(excised_array, buffer_length);
  int i;
  for(i=0;i<buffer_length;i++) {
    excised_array[i]='\0';
  }//ANOTHER COMMENT

  //This loop contains the excision logic, the outermost 'if' handles the 4 possible cases
  // Case (0)  The current index is inside a comment (of some type).
  // Case (1)  The current index _is_ at the beginning of '//' style comment.
  // Case (2)  The current index might be at the beginning of a '/**/' style comment.
  //       (2a) The current index was not the beginning of a '/**/' style comment (no closing '*/').
  //       (2b) The current index was at the beginning of '/**/' (closing '*/').
  // Case (3)  The current index is not in a comment.
  for (index_inbuffer=0;index_inbuffer < buffer_length; ++index_inbuffer) {
    if (INCOMMENT) {
      if (slash_slash) {
	if (code_array[index_inbuffer] == '\n') {
	  INCOMMENT = 0;
	  slash_slash = 0;
	  excised_array[index_outbuffer++] = '\n';
	}/*Also this/* // */
      } else if (code_array[index_inbuffer] == '/' && code_array[index_inbuffer-1] == '*') {INCOMMENT = 0;}
    } else if (index_inbuffer > 0 && code_array[index_inbuffer] == '/' && code_array[index_inbuffer-1] == '/') {
      slash_slash = 1;
      INCOMMENT = 1;
      index_outbuffer--;
    } else if (index_inbuffer > 0 && code_array[index_inbuffer] == '*' && code_array[index_inbuffer-1] == '/') {
      incomment_index = index_inbuffer;
      while (incomment_index < buffer_length) {
	incomment_index++;
	if (code_array[incomment_index] == '/' && code_array[incomment_index-1] == '*') {
	  INCOMMENT = 1;
	  index_outbuffer--;
	  break;
	}
      }
      if (!INCOMMENT) {
	excised_array[index_outbuffer++] = code_array[index_inbuffer];
      }
    } else {
      excised_array[index_outbuffer++] = code_array[index_inbuffer];
    }
  }
  excised_array[index_outbuffer] = '\0';
  excised_array = realloc(excised_array, index_outbuffer+1);
  return excised_array;
}

char* read_file_chars_into_heap_array(char* filename, char* heap_chars){
  //(filename string, heap_chars pointer) --> ptr_to_heap_chars with file bytes
  // INVARIANT:  The file is terminated by EOF, and contains chars.
  FILE* fp;
  fp = fopen(filename, "r");
  int i = 0;
  char c;
  while(EOF != (c = getc(fp))){i++;}
  printf("i is: %i\n", i);
  heap_chars = realloc(heap_chars, i+1);
  rewind(fp);
  int k;
  for(k = 0; k<i; k++){
    heap_chars[k] = getc(fp);
  }
  heap_chars[k] = '\0';
  fclose(fp);
  return heap_chars;
}


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
