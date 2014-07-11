#include <stdio.h>
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
  parent = argv[1];
  targets = argv[2];
  squeezeouts(parent, targets);
  printf("parent: %s", parent);
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
