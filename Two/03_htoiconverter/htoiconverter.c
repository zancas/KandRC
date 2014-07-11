#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int htoi(char charrepofhex[], int len);
int exponentiator(int base, int exponent);
int fromhexbuffer[1000];
int main(int argc, char** argv)
{
  if (argc != 2) {
    printf("You must pass a string of hexchars to convert to decimal as argument.\n");
    return -1;
  }
  printf("Result: %d\n", htoi(argv[1], strlen(argv[1])));
  return 0;
}


int htoi(char* charrepofhex, int length){
  int forwardindex;
  int revindex;
  int result;
  revindex = 0;
  result = 0;
  char* reversed = (char*) calloc(length, 1);
  for(forwardindex = length-1; forwardindex >=0 ; --forwardindex, ++revindex){
    reversed[revindex] = charrepofhex[forwardindex];
  }
  for(revindex=0; revindex<length; revindex++){
    if (reversed[revindex] == 'a' || reversed[revindex] == 'A') {
      result = result + 10 * exponentiator(16, revindex);
    }
    else if (reversed[revindex] == 'b' || reversed[revindex] == 'B') {
      result = result + 11 * exponentiator(16, revindex);
    }
    else if (reversed[revindex] == 'c' || reversed[revindex] == 'C') {
      result = result + 12 * exponentiator(16, revindex);
    }
    else if (reversed[revindex] == 'd' || reversed[revindex] == 'D') {
      result = result + 13 * exponentiator(16, revindex);
    }
    else if (reversed[revindex] == 'e' || reversed[revindex] == 'E') {
      result = result + 14 * exponentiator(16, revindex);
    }
    else if (reversed[revindex] == 'f' || reversed[revindex] == 'F') {
      result = result + 15 * exponentiator(16, revindex);
    }
    else {
      result = result + (reversed[revindex] - '0') * exponentiator(16, revindex);
    }
  }
  free(reversed);
  return result;
}

int exponentiator(int base, int exponent) {
  /* Calculates base raised to the exponent. */
  int result = 1;
  int i;
  for ( i = 0; i < exponent; i++) {
    result = result * base;
  }
  return result;
}
