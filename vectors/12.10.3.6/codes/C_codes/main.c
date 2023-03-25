#include<stdio.h>
#include <math.h>
#include "lib.h"
/* code by B.Prathyusha (works on termux)
March 25, 2023
Link to license("https://github.com/prathyushabana/FWC/blob/main/LICENSE")
Find a and b, if (a+b)(a-b)=8 and a=8b.*/

double quadratic(double coefa,double coefb,double constant);
int main()
{
  double a,b;
  
  b=quadratic(63.0,0.0,-8.0);//63*b^2=8
  a=8*b;//a=8*b
  printf("b=%lf \n",b);
  printf("a=%lf \n",a);
      
  return 0;
}


