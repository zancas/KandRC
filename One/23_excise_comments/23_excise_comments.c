#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* '/*''s and '//''s are used to
   indicate comment entry. Comment state is recorded with an INCOMMENT
   boolean flag. putchar is not called while INCOMMENT is 1 */

char* read_file_chars_into_heap_array(char* filename, char* heap_chars);
char* excise_comments(char* code_array, char* excised_array);

int main(int argc, char** argv)
{
  if(argc != 2){
    printf("You must pass the name of the file to analyze, as the only argument. \n");
    return -1;
  }

  printf("Filename: %s\n", argv[1]);
  char* raw_c_array = (char *) malloc(1);
  char* commentless_c = (char *) malloc(1);
  raw_c_array = read_file_chars_into_heap_array(argv[1], raw_c_array);
  commentless_c = excise_comments(raw_c_array, commentless_c);
  printf("Post Excision:\n%s\n", commentless_c);
  free(commentless_c);
  free(raw_c_array);
  return 0;
}

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
      if(slash_slash) {
	if(code_array[index_inbuffer] == '\n') {
	  INCOMMENT = 0;
	  slash_slash = 0;
	  excised_array[index_outbuffer++] = '\n';
	}/*Also this/* // */
      }
      if(code_array[index_inbuffer] == '/' && code_array[index_inbuffer-1] == '*') {INCOMMENT = 0;}
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
      if(!INCOMMENT) {
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
