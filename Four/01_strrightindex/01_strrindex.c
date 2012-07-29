#include <stdio.h>
#include <string.h>
#define MAXLINE 1000 /* maximum input line length */
int zagetline(char s[], int lim);
void repcarreturns(char crstring[]);
// FOOOOOOOOOOOL
int strindex(char source[], char target[]);
void reverse(char s[]);
int strrindex(char source[], char target[]);

char pattern[] = "1"; /* pattern to search for */

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

/* represent carriage returns */
void repcarreturns(char crstring[])
{
  char crstringrepr[strlen(crstring)];
  int q;
  for ( q = 1; q < strlen(crstring); q++) {
    crstringrepr[q-1] = crstring[q];
  }
  crstringrepr[q-1] = '\0';
  printf("Here's a representation of the source string that strindex got: '\\n'%s\n", crstringrepr);      
  return;
}

/* strindex: return index of target in source, -1 if none */
int strindex(char source[], char target[])
{
  int i, j, k;
  if (source[0] == '\n') {repcarreturns(source);}
  printf("Here's the value of the target string that strindex got: %s\n", target);
  for (i = 0; source[i] != '\0'; i++) {
    for (j=i, k=0; target[k]!='\0' && source[j]==target[k]; j++, k++)
      ;
    if (k > 0 && target[k] == '\0') {
      printf("We have a match! The length of the target is: %d\n", k);
      printf("We have a match! The start index of the target is: %d\n", i);
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

/* find the rightmost index in source matching target */
int strrindex(char source[], char target[])
{
  int fromright, leftindex, lensource, lentarget;
  lensource = strlen(source);
  lentarget = strlen(target);
  reverse(source);
  reverse(target);
  fromright = strindex(source, target);
  if (fromright == -1) {return -1;}
  leftindex = lensource - (fromright + lentarget);
  return leftindex;
}
