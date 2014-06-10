#include <stdio.h>

/*print Fahrenheit-Celsius table
 for fahr = 0, 20, ..., 300; floating point version*/

int fahr_to_cels(int fahr) {
  return (5.0/9.)*(fahr - 32.0);
}

main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;    /* lower limit of temperature table */
  upper = 300;  /* upper limit of temperature table */
  step = 20;    /* step size */

  fahr = lower;
  printf("== Temperature Table ==\n");
  printf("Fahrenheit:    Celsius:\n");
  while (fahr <= upper) {
    celsius = fahr_to_cels(fahr);
    printf("%10.0f %11.1f\n", fahr, celsius);
    fahr = fahr + step;
  }

  return 0;
}
