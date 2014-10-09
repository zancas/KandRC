#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char* reverser(char* to_reverse);

int main(int argc, char** argv){
  char* from_reverser;
  from_reverser = reverser(argv[1]);
  printf("%s\n", from_reverser);
  free(from_reverser);
  return 0;
}

char* reverser(char* to_reverse){
  int length = strlen(to_reverse);
  char* reversed = (char*)calloc(length, 1);
  int j = 0;
  for(int i = length-1; i >= 0; i--, j++){
    reversed[j] = to_reverse[i];
  }
  reversed[++j] = '\0';
  return reversed;
}
