#include <stdio.h>

/*print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300; floating point version*/
main()
{
  float fahr, celsius;
  int lower, upper, step;
  
  lower = 0;    /* lower limit of temperature table */
  upper = 300;  /* upper limit of temperature table */
  step = 20;    /* step size */

  celsius = lower;
  printf("== Temperature Table ==\n");  
  printf("Celsius:    Fahrenheit:\n");
  while (celsius <= upper) {
    fahr = ((9.0/5.0) * celsius) + 32.0;
    printf("%7.0f %14.0f\n", celsius, fahr);
    celsius = celsius + step;
  }

  return 0;
}
