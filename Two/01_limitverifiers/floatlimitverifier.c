#include <float.h>
#include <stdio.h>

void float_rangefinder(void);
float exponentiator(float base, int exponent);

/* Problems:
   (1)  Precision limits of floats may make arithmetic operands too insiginificant to change the size of the large floating operand.
   (2)  The Epsilon limit, again (I _think_) a product of the number of bits in the significand, of floats makes multiplication by small numbers of limited utility.
   (3)  All this suggests the invention of a new type for the resolution of the range problem..  to be continued...*/

int main(int argc, char** argv) {
  printf("Limit:\t\tValue:\n");
  printf("--------------------------------------\n");
  printf("Limit:\t\tValue:\n");
  printf("FLT_RADIX:\t% d\n", FLT_RADIX);
  printf("FLT_ROUNDS:\t% d\n", FLT_ROUNDS);
  printf("FLT_DIG:\t% d\n", FLT_DIG);
  printf("FLT_EPSILON:\t%.20f\n", FLT_EPSILON);
  printf("FLT_MANT_DIG:\t% d\n", FLT_MANT_DIG);
  printf("FLT_MAX:\t% f\n",  FLT_MAX);
  printf("FLT_MAX_EXP:\t% d\n", FLT_MAX_EXP);
  printf("FLT_MIN:\t%.20f\n", FLT_MIN);
  printf("FLT_MIN_EXP:\t% d\n", FLT_MIN_EXP);
  printf("DBL_DIG:\t% d\n", DBL_DIG);
  printf("DBL_EPSILON:\t%.20f\n", DBL_EPSILON);
  printf("DBL_MANT_DIG:\t% d\n", DBL_MANT_DIG);
  printf("DBL_MAX:\t% f\n", DBL_MAX);
  printf("DBL_MAX_EXP:\t% d\n", DBL_MAX_EXP);
  printf("DBL_MIN:\t%.390f\n", DBL_MIN);
  printf("DBL_MIN_EXP:\t% d\n", DBL_MIN_EXP);
  printf("--------------------------------------\n");
  float_rangefinder();
  return 0;
}

void float_rangefinder(void) {
  float prevprev = 0;
  float prev = 0;
  int exponent = 1;
  float final_val = 1;
  /* Now we are within a factor of 2! */
  while (final_val != prev) {
    prevprev = exponentiator(2, exponent-1);
    prev = exponentiator(2, exponent);
    exponent++;
    final_val = exponentiator(2, exponent);
  }
  /* Set values.  AAAAKKK...   need a better type for this. */
  final_val = prevprev;

  int i = 1;
  /* while */
  long long int testint;
  testint = 1;
  printf("testint: %lld\n", testint);
  exponent = 1;
  printf("Maximum * float size is: %f\n", final_val);
  float anotherfloat = final_val * .999999;
  printf("New max guess is final_val + anotherfloat = %f\n", final_val + anotherfloat + .001);
  printf("anotherfloat is: %f\n", anotherfloat);
  double multfact = 1.0;
  float lastiteration = 0;
  float iterbeforelast = 0;
  int stopper = 0;
  int shift = 0;
  double digit;
  double prevmultfact;
  /* Now multiply by factors increasingly close to 2. */
  while( final_val != prev && stopper < 11) {
    digit = 9.0;
    iterbeforelast = lastiteration;
    lastiteration = final_val;
    prevmultfact = multfact;
    multfact = multfact + digit/exponentiator(10, exponent);
    printf("multfact is: %f\n", multfact);
    final_val = final_val * multfact;
    printf("final_val is: %f\n", final_val);
    while (final_val == prev && exponent < 20) {
      digit = 9.0;
      while (digit > 0 && (final_val == prev)) {
	multfact = prevmultfact;
	multfact = multfact + digit/exponentiator(10, exponent);
	final_val = final_val * multfact;
	digit--;
      }
      printf("multfact is: %.20f\n", multfact);
      printf("final_val is: %.20f\n", final_val);
      exponent++;
    }
    exponent++;
    stopper++;
  };
  final_val = iterbeforelast;
  printf("multfact is: %f\n", multfact);
  printf("Maximum float size is: %f\n", final_val);
}

float exponentiator(float base, int exponent) {
  /* Calculates 2 raised to the exponent. */
  float result = 1;
  int i;
  for ( i = 0; i < exponent; i++) {
    result = result * base;
  }
  return result;
}
