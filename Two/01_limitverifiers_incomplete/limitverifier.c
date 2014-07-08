#include <limits.h>
#include <float.h>
#include <stdio.h>
/*   */

void char_rangefinder(void);
void ulong_rangefinder(void);
void float_rangefinder(void);
float exponentiator(float base, int exponent);

int main(int argc, char** argv) {
  printf("Limit:\t\tValue:\n");
  printf("--------------------------------------\n");
  printf("CHAR_MAX:\t% d\n", CHAR_MAX);
  printf("CHAR_MAX>>1:\t% d\n", CHAR_MAX>>1);
  printf("CHAR_MIN:\t% d\n", CHAR_MIN);
  printf("UCHAR_MAX:\t% d\n", UCHAR_MAX);
  printf("INT_MAX:\t% d\n", INT_MAX);
  printf("INT_MIN:\t% d\n", INT_MIN);
  printf("UINT_MAX:\t %u\n", UINT_MAX);
  printf("SHRT_MAX:\t% d\n", SHRT_MAX);
  printf("SHRT_MIN:\t% d\n", SHRT_MIN);
  printf("USHRT_MAX:\t% d\n", USHRT_MAX);
  printf("LONG_MAX:\t% ld\n", LONG_MAX);
  printf("LONG_MAX+1:\t% ld\n", LONG_MAX+1);
  printf("LONG_MAX+2:\t% ld\n", LONG_MAX+2);
  printf("LONG_MIN:\t% ld\n", LONG_MIN);
  printf("ULONG_MAX:\t %lu\n", ULONG_MAX);
  printf("ULONG_MAX+1:\t %lu\n", ULONG_MAX+1);
  printf("ULONG_MAX+2:\t %lu\n", ULONG_MAX+2);


  printf("--------------------------------------\n");
  char_rangefinder();
  ulong_rangefinder();
  printf("--------------------------------------\n");

  printf("Limit:\t\tValue:\n");
  printf("FLT_RADIX:\t% d\n", FLT_RADIX);
  printf("FLT_ROUNDS:\t% d\n", FLT_ROUNDS);
  printf("FLT_DIG:\t% d\n", FLT_DIG);
  printf("FLT_EPSILON:\t% f\n", FLT_EPSILON);
  printf("FLT_MANT_DIG:\t% d\n", FLT_MANT_DIG);
  printf("FLT_MAX:\t% f\n",  FLT_MAX);
  printf("FLT_MAX_EXP:\t% d\n", FLT_MAX_EXP);
  printf("FLT_MIN:\t% f\n", FLT_MIN);
  printf("FLT_MIN_EXP:\t% d\n", FLT_MIN_EXP);
  printf("DBL_DIG:\t% d\n", DBL_DIG);
  printf("DBL_EPSILON:\t% f\n", DBL_EPSILON);
  printf("DBL_MANT_DIG:\t% d\n", DBL_MANT_DIG);
  printf("DBL_MAX:\t% f\n", DBL_MAX);
  printf("DBL_MAX_EXP:\t% d\n", DBL_MAX_EXP);
  printf("DBL_MIN:\t% f\n", DBL_MIN);
  printf("DBL_MIN_EXP:\t% d\n", DBL_MIN_EXP);


  printf("--------------------------------------\n");

  float_rangefinder();

  return 0;
}

void char_rangefinder(void) {
  /* If you make a number larger than the largest possible size, what can happen?
   In this version of C x86_64, gcc something-or-other it wraps. */
  char final_size = 1;
  char max_size;
  char min_size;
  while (final_size > 0) {
    final_size = final_size<<1;
  }
  min_size = final_size;
  max_size = ~final_size; /* Con cuidado, ~ casts to int! */
  printf("Maximum char size is: %d\n", max_size);
  printf("Minimum char size is: %d\n", min_size);
}

void ulong_rangefinder(void) {
  /* If you make a number larger than the largest possible size, what can happen?
   In this version of C x86_64, gcc something-or-other it wraps. */
  unsigned long final_size = 1;
  unsigned long max_size;
  unsigned long min_size;
  while (final_size > 0) {
    final_size = final_size<<1;
  }
  min_size = final_size;
  max_size = ~final_size; /* Con cuidado, ~ casts to int! */
  printf("Maximum ulong size is: %lu\n", max_size);
  printf("Minimum ulong size is: %lu\n", min_size);
}


void float_rangefinder(void) {
  float pp_val = 0;
  float prev_val = 0;
  float tester = 1;
  int exponent = 1;
  float final_val = 0;

  while (tester != prev_val) {
    pp_val = exponentiator(2, exponent-1);
    prev_val = exponentiator(2, exponent);
    exponent++;
    tester = exponentiator(2, exponent);
  }
  final_val = pp_val + (pp_val - 1.);
  printf("Maximum ***  float size is: %f\n", final_val);
  printf("Maximum float size is: %f\n", pp_val - 1.);
  float newttestfloat = 1;
  printf("newttestfloat: %f\n", newttestfloat);
  newttestfloat = (newttestfloat + 3) / 42;
  printf("newttestfloat: %f\n", newttestfloat);
  newttestfloat = FLT_MAX;
  printf("newttestfloat/2: %f\n", newttestfloat/2);
  printf("newttestfloat/2+1: %f\n", newttestfloat/2+1);
  int decrementer = 0;
  float new_test = 17014118346046923173168730371588410572.;
  printf("new_test: %f\n", new_test);
  /*while (new_test == dec_float) {
    newttestfloat = newttestfloat - decrementer;
    decrementer++;
  }
  exponent = tester = 1;
  prev_val = 0;
  while (prev_val != tester) {
    tester = exponentiator(.5, exponent);
    exponent++;
  }
  printf("Minimum float size is: %f\n", tester);*/

}


/* A function that finds the smallest int whose base 2 representation has a MSB larger than the largest value possible for its argument. */

float exponentiator(float base, int exponent) {
  /* Calculates 2 raised to the exponent. */
  float result = 1;
  int i;
  for ( i = 0; i < exponent; i++) {
    result = result * base;
  }

  return result;
}
