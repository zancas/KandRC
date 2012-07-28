#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */
int zagetline(char s[], int lim);

// FOOOOOOOOOOOL
int strindex(char source[], char searchfor[]);
void reverse(char s[]);
int strrindex(char source[], char searchfor[]);

char pattern[] = "123"; /* pattern to search for */

/* find all lines matching pattern */
main()
{
  char line[MAXLINE];
  int found = 0;
  int findindex;

  while (zagetline(line, MAXLINE) > 0) 
    {
      if ( (findindex = strrindex(line, pattern)) >= 0) {
	found++;
	reverse(line);
	reverse(pattern);
	printf("The start index of the right most instance of:\n");
	printf("%s\n", pattern);
	printf("in line:\n");
	printf("%s",line);
	printf("is %d\n", findindex);
      }
    }
  return found;
}

/* zagetline: get line into s, return length */
int zagetline(char s[], int lim)
{
  int c, i;

  i = 0;
  while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
    s[i++] = c;
  if (c == '\n')
    s[i++] = c;
  s[i] = '\0';
  return i;
  }

/* strindex: return index of t in s, -1 if none */
int strindex(char s[], char t[])
{
  int i, j, k;

  printf("Here's the value of \"s\" that strindex got: %s\n", s);
  printf("Here's the value of \"t\" that strindex got: %s\n", t);
  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0') {
      printf("We have a match! \"k\" is: %d\n", k);
      printf("We have a match! \"i\" is: %d\n", i);
      return i;
    }
  }
  return -1;
}

/* reverse:  return a reversed copy of string s */
void reverse(char s[]) 
{
  char c;
  int i,j;
  for (i = 0, j = strlen(s)-1; i<j; i++, j--) {
    c = s[i];
    s[i] = s[j];
    s[j] = c;
  }
}

/* find the rightmost index in source matching searchfor */
int strrindex(char source[], char searchfor[])
{
  int fromright, leftindex, lensource, lensearchfor;
  lensource = strlen(source);
  lensearchfor = strlen(searchfor);
  reverse(source);
  reverse(searchfor);
  fromright = strindex(source, searchfor);
  if (fromright == -1) {return -1;}
  leftindex = lensource - (fromright + lensearchfor) - 1;
  return leftindex;
}
