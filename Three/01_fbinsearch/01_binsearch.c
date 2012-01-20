#include <stdio.h>
#include <string.h>

/* fbinsearch: find x in v[0] <= v[1] ... <= v[n-1] */

int fbinsearch(int x, int v[], int n);
int binsearch(int x, int v[], int n);

main() 
{
  int result, targval, i, n;
  targval = 12;
  n = 5;
  int numarray[n];
  for (i=0; i < n; i++) {
    numarray[i] = i*3;
    printf("numarray[%d] = %d\n",i, numarray[i]);
  }

  int counter = 0;
  while (counter < 100000000) {
    result = binsearch(targval, numarray, n);
    counter++;
  }
  printf("The value is at index = %d; Where targval is %d\n",result, targval);

    
  return 0;
}

int fbinsearch(int x, int v[], int n) {
  int low, mid, high;
  
  low = 0;
  high = n - 1;
  while (low < high) {
    mid = (low+high)/2;
    if (x <= v[mid]) {
      high = mid;
    }else{
      low = ++mid;
    }  
  }
  if (v[mid] == x) {
    return mid;
  } else {
    return -1;
  }
}

int binsearch(int x, int v[], int n) {
  int low, mid, high;
  
  low = 0;
  high = n - 1;
  while (low <= high) {
    mid = (low+high)/2;
    if (x < v[mid]) {
      high = mid-1;
    }else if (x > v[mid]){
      low = mid+1;  
    }else {  /* found match */
      return mid;
    }
  }
  return -1;
}


