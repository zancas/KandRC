#include <stdio.h>
#include <stdlib.h>


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
  printf("%s\n", heap_chars);
  return heap_chars;
}

int main(int argc, char** argv)
{
  if(argc != 2){
    printf("Must have 2 args.\n");
    return -1;
  }
  printf("Filename: %s\n", argv[1]);
  char* heap_array = (char *) malloc(1);
  heap_array = read_file_chars_into_heap_array(argv[1], heap_array);
  free(heap_array);
  return 0;
}
