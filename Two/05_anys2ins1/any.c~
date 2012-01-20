#include <stdio.h>
/* squeeze out all chars in s1 that match any char in s2  */

void squeezeouts2(char s1[], char s2[]);

main() 
{
  char teststring[17] = "Test string one.";
  char vowels[6] = "aeiou";
  squeezeouts2(teststring, vowels);
  printf("teststring: %s\n", teststring);
}

void squeezeouts2(char s1[], char s2[]) {
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
