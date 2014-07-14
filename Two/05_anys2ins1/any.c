#include <stdio.h>
#include <stdlib.h>
/* return index of first occurence of a chars in s1 that matches any char in s2  */

int any(char s1[], char s2[]);

int main(int argc, char** argv)
{
  if (argc != 3) {
    printf("You must pass 2 strings to this function, the first index of the first");
    printf(" containing a char also in the second will be returned.\n");
    return -1;
  }
  char* parent;
  char* targets;
  parent = argv[1];
  targets = argv[2];
  printf("Result: %d\n", any(parent, targets));
}

int any(char s1[], char s2[]) {
  int i ,j, k;
  int charfound = 0;
  for(i = j = 0; s1[i] != '\0'; i++) {
    k = 0;
    while (1) {
      if (s1[i] == s2[k]) {
	charfound = 1;
	break;
      }
      else if (s2[k] == '\0'){
	break;
      }else {k++;}
    }
    if (charfound){
      break;
    }
  }
  if (charfound) {
    return i;
  } else {
    return -1;
  }
}
