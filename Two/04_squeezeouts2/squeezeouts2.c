#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* squeeze out all chars in s1 that match any char in s2  */

void squeezeouts(char s1[], char s2[]);

int main(int argc, char** argv)
{
  if(argc != 3){
    printf("You must pass 2 strings to this function, the chars in the second will be removed from the first.\n");
    return -1;
  }
  char* parent;
  char* targets;
  parent = (char*) calloc(strlen(argv[1]), 1);
  targets = (char*) calloc(strlen(argv[2]), 1);
  parent = argv[1];
  printf("parent is %s.\n", parent);

  //squeezeouts(teststring, vowels);
  //printf("teststring: %s\n", teststring);
  free(parent);
  free(targets);
  return 0;
}

void squeezeouts(char* s1, char* s2) {
  int i ,j, k;
  for(i = j = 0; s1[i] != '\0'; i++) {
    k = 0;
    while (1) {
      if (s1[i] == s2[k]) {break;}
      else if (s2[k] == '\0'){
	s1[j++] = s1[i];
	break;
      }else {k++;}
    }
  }
  s1[j] = '\0';
}
