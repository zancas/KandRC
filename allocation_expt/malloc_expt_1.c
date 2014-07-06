#include <stdlib.h>
#include <stdio.h>
#include <string.h>


(correct_length) --> dynamic memory of correct length, extra bytes zeroed

char* pack_char_array(char** char_ptr_ptr){
  //Warning assuming '\0' array terminator
  int char_array_index = 0;
  while(char_ptr_ptr[char_array_index] != '\0'){char_array_index++;}
  char_ptr_ptr = realloc(char_ptr_ptr, char_array_index+1);
  return char_array_ptr_ptr;
}

int main(int argc, char **argv)
{
  if(argc != 2){
    printf("Must pass 1 argument!\n");
    return -1;
  }
  char* test_array;
  test_array = argv[1];
  printf("test_array is: %s\n", test_array);
  char* test_array_2;
  printf("length: %i\n", strlen(test_array));
  test_array_2 = (char *) malloc(strlen(argv[1]));
  strncpy(test_array_2, argv[1], strlen(argv[1]));
  printf("test_array_2 is: %s\n", test_array_2);
  pack_char_array(&test_array_2);

  return 0;
}
