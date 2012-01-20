#include <stdio.h>
#include <string.h>

/* count blanks, tabs, add newlines*/

void escape(char *s, char *t);  
void unescape(char *s, char *t);  
main(int argc, char *argv[])
{
  if (argv[1] == NULL){
    printf("NO!\n");
    return 15;
  }
  printf("argv[1] is %s\n", argv[1]);
  char targstring[strlen(argv[1])*2 + 1];
  escape(targstring, argv[1]);
  printf("Input: %s\nOutput: %s\n",argv[1], targstring);
  char newout[strlen(argv[1])+1];
  unescape(newout, targstring);
  printf("Input: %s\nOutput: %s\n", targstring, newout);


  return 0;
}

void escape(char *s, char *t){
  int outcounter, incounter;
  outcounter = incounter = 0;
  while(t[incounter] != '\0')
    {     
      switch(t[incounter]) {
      case '\t':
	s[outcounter] = '\\';
	outcounter++;
	s[outcounter] = 't';
	break;
      case '\n':
	s[outcounter] = '\\';
	outcounter++;
	s[outcounter] = 'n';
	break;
      default:
	s[outcounter] = t[incounter];
	break;
      }
      outcounter++;
      incounter++;
    }
  s[outcounter] = '\0';
}

void unescape(char *s, char *t){
  int outcounter, incounter;
  outcounter = incounter = 0;
  while(t[incounter] != '\0')
    {     
      switch(t[incounter]) {
      case '\\':
	if (t[incounter+1] == 't') {
	  incounter++;
	  s[outcounter] = '\t';
	  break;
	} else if (t[incounter+1] == 'n') {
	  incounter++;
	  s[outcounter] = '\n';
	  break;
	} else {
	  s[outcounter] = t[incounter];
	  break;
	}
      default:
	s[outcounter] = t[incounter];
	break;
      }
      outcounter++;
      incounter++;
    }
  s[outcounter] = '\0';
}
