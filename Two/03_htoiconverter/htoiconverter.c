#include <stdio.h>
int htoi(char charrepofhex[], int len);
int exponentiator(int base, int exponent);
int fromhexbuffer[1000];
int fromh;
main() 
{
  char testarray[2] = "11";
  fromh = htoi(testarray, 1);
  return 0;
}


int htoi(char charrepofhex[], int length){
  int forwardindex, revindex, result;
  revindex = result = 0;
  char reversed[length];
  for(forwardindex = length; forwardindex >=0 ; --forwardindex, ++revindex){
    reversed[revindex] = charrepofhex[forwardindex];
  }
  for(revindex=0; revindex<=length; revindex++){
    printf("revindex: %d\n", revindex);
    printf("reversed[revindex]: %d\n", reversed[revindex]);
    printf("reversed[revindex]-'0': %d\n", reversed[revindex]-'0');
    if (reversed[revindex] == 'a' || reversed[revindex] == 'A') {
      printf("Are we executng this?\n");
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
      printf("result = %d\n", result);
    }
  }
  printf("\nresult: %d\n", result);
  return result;
}

int exponentiator(int base, int exponent) {
  /* Calculates base raised to the exponent. */
  int result = 1;
  int i;
  for ( i = 0; i < exponent; i++) {
    result = result * base;
    printf("How many times does exponentiator execute?\n");
  }
  
  return result;
}
