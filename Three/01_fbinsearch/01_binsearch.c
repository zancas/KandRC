#include <stdio.h>
#include <string.h>
#include <time.h>

/* fbinsearch: find x in v[0] <= v[1] ... <= v[n-1] */

int fbinsearch(int x, int v[], int n);
int binsearch(int x, int v[], int n);

main() 
{
  int result, targval, i, n;
  int binsearchtime, fbinsearchtime, baseline;
  double sbinsearchtime, sfbinsearchtime;
  targval = 72;
  n = 50;
  int numarray[n];
  for (i=0; i < n; i++) {
    numarray[i] = i*3;
    printf("For binsearch: numarray[%d] = %d\n",i, numarray[i]);
  }

  int counter = 0;
  baseline = clock();
  while (counter < 100000000) {
    result = binsearch(targval, numarray, n);
    counter++;
  }
  binsearchtime = clock() - baseline;
  sbinsearchtime = binsearchtime / (double)CLOCKS_PER_SEC;
  printf("Total time for 100000000 binsearches = %3.3f\n", sbinsearchtime);
  printf("The value is at index = %d; Where targval is %d\n",result, targval);
  

  counter = 0;
  baseline = clock();
  while (counter < 100000000) {
    result = fbinsearch(targval, numarray, n);
    counter++;
  }
  fbinsearchtime = clock() - baseline;
  sfbinsearchtime = fbinsearchtime / (double)CLOCKS_PER_SEC;
  printf("Total time for 100000000 fbinsearches = %3.3f\n", sfbinsearchtime);
  printf("For fbinsearch: The value is at index = %d; Where targval is %d\n",result, targval);

    
  printf("The result of calling clock/CLOCKS_PER_SEC: %3.3f\n", clock()/(double)CLOCKS_PER_SEC);
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


