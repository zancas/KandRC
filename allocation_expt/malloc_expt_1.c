#include <stdlib.h>
#include <stdio.h>

char* pack_char_array(char* char_array_ptr){
  //Warning assuming '\0' array terminator
  int char_array_index = 0;
  while(char_array_ptr[char_array_index] != '\0'){char_array_index++;}
  char_array_ptr = realloc(char_array_ptr, char_array_index+1);
  return char_array_ptr;
}

int main(int argc, char **argv)
{
  if(argc != 2){
    printf("Must pass 1 argument!\n");
    return -1;
  }
  printf("%s\n", argv[1]);
  char* packed_array;
  return 0;
}
