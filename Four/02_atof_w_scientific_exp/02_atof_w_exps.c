#include <stdio.h>
#include <string.h>

#define MAXLINE 100

/* Exercise 4.2 Extends atof. */
int zagetline(char line[], int lim);
double atof(char []);
int strindex(char s[], char t[]);
int getexponent(char s[], int e_index);
int trimtrail(char s[]);
int atoi(char s[]);

main()
{
  char line[MAXLINE];
  zagetline(line, MAXLINE);
  printf("Input was string output is float: \t'%g'.\n", atof(line));
  return 0;
}


/* zagetline: get first arg into line, return length */
int zagetline(char line[], int lim)
{
  int c, i;

  i = 0;
  while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
    line[i++] = c;
  if (c == '\n')
    line[i++] = c;
  line[i] = '\0'; 
  return i;
}

/* atof:  convert string s to double */
double atof(char s[])
{
  double val, power, exponent_val;
  int i, sign, e_index, exponent;
  
  if ((e_index = strindex(s, "e")) != -1 || (e_index = strindex(s, "E")) != -1) {
    int exp_sign;
    /* Convert to e-less notation. */
    exponent = getexponent(s, e_index);
    s[e_index] = '\0';
    exponent_val = 1.0;
    if ( exponent < 0 ) {
      exponent = -1 * exponent;
      exp_sign = '-';
    } else {exp_sign = '+';}
    for (;exponent > 0; exponent--) {
      exponent_val *= 10.0;
    }
    if (exp_sign == '-') {exponent_val = 1/exponent_val;}

  } else {exponent_val = 1.0;}
  for (i = 0 ; isspace(s[i]) ; i++) /* skip space char(s) */
    ;
  sign = (s[i] == '-') ? -1 : 1 ; 
  if (s[i] == '+' || s[i] == '-') i++;
  for (val = 0.0 ; isdigit(s[i]) ; i++)
    val = 10.0 * val + (s[i] - '0');
  if (s[i] == '.') {i++;}
  for (power = 1.0 ; isdigit(s[i]) ; i++) {
    val = 10.0 * val + (s[i] - '0');
    power *= 10.0;
  }
  return  sign * exponent_val * val / power;
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

/* getexponent: obtain exponent as char[] and return as int. */
int getexponent(char s[], int e_index)
{
  int shiftind, lengthofshiftnum, exponent, i;
  trimtrail(s);
  shiftind = e_index + 1;  
  lengthofshiftnum = strlen(s) - shiftind;
  char result[lengthofshiftnum];
  for (i = 0; shiftind < strlen(s) ; i++, shiftind++) {
    result[i] = s[shiftind];
  }
  result[i] = '\0';
  exponent = atoi(result);
  return exponent;
}

/* trimtrail: remove trailing blanks, tabs, newlines */
int trimtrail(char s[])
{
  int n;

  for (n = strlen(s)-1 ; n >= 0 ; n--){
    if(s[n] != ' ' && s[n] != '\t' && s[n] != '\n')
      break;
  }
  s[n+1] = '\0';
  return n;
}

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
