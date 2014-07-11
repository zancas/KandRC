#include <stdio.h>
/* squeeze out all chars in s1 that match any char in s2  */

int any(char s1[], char s2[]);

int main(int argc, char** argv)
{
  char teststring[17] = "Tsta strng n.";
  char vowels[6] = "aeiou";

  printf("Where char was found: %d\n", any(teststring, vowels));
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
