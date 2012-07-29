#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 100

/* I can't use strlen because it's dependent on some weirdo type stuff I don't understand. */
/* rudimentary calculator */
int strindex(char s[], char t[]);
double atof(char []);
int zagetline(char line[], int max);
int getexponent(char s[], int e_index);
int trim(char s[]);
int atoi(char s[]);

/* atoi:  convert s to integer; version 2 */
int atoi(char s[])
{
  int i, n, sign;
  i = 0;
  sign = (s[i] == '-') ? -1 : 1;
  if (s[i] == '+' || s[i] == '-') i++; /* skip sign */
  for (n = 0 ; isdigit(s[i]); i++)
    n = 10 * n + (s[i] - '0');
  return sign * n;
}
/* atof:  convert string s to double */
double atof(char s[])
{
  double val, power;
  int i, sign, exponent;

  int e_index, p_index;
  
  if ((e_index = strindex(s, "e")) != -1 || (e_index = strindex(s, "E")) != -1) {
    printf("e_index is %d\n", e_index);
    if ((p_index = strindex(s, ".")) == -1) {
      p_index = e_index;
    }
    /* Convert to e-less notation. */
    printf("p_index is %d\n", p_index);
    exponent = getexponent(s, e_index);
    printf("exponent is %d\n", exponent);
  }
  
  for (i = 0 ; isspace(s[i]) ; i++) /* skip space char(s) */
    ;
  sign = (s[i] == '-') ? -1 : 1 ; 
  if (s[i] == '+' || s[i] == '-') i++;
  for (val = 0.0 ; isdigit(s[i]) ; i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] = '.') i++;
  for (power = 1.0 ; isdigit(s[i]) ; i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  return sign * val / power;
}

/* getexponent: obtain exponent as char[] and return as int. */
int getexponent(char s[], int e_index)
{
  int shiftind, lengthofshiftnum, exponent, i;
  trim(s);
  shiftind = e_index + 1;  
  lengthofshiftnum = strlen(s) - shiftind;
  char result[lengthofshiftnum];
  for (i = 0; shiftind < strlen(s) ; i++, shiftind++) {
    result[i] = s[shiftind];
  }
  exponent = atoi(result);
  return exponent;
}

/* trim: remove trailing blanks, tabs, newlines */
int trim(char s[])
{
  int n;

  for (n = strlen(s)-1 ; n >= 0 ; n--){
    if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
      break;
  }
  s[n+1] = '\0';
  return n;
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

  for (i = 0; s[i] != '\0'; i++) {
    for (j=i, k=0; t[k]!='\0' && s[j]==t[k]; j++, k++)
      ;
    if (k > 0 && t[k] == '\0')
      return i;
  }
  return -1;
}

main()
{
  double sum;
  char line[MAXLINE];
  sum  = 0;
  while (zagetline(line, MAXLINE) > 0)
    printf("sum is: \t%g\n", sum += atof(line));
  return 0;
}
