/* code by B.Prathyusha (works on termux)
March 23, 2023
Link to license("https://github.com/prathyushabana/FWC/blob/main/LICENSE")
Given that a.b=0 and axb=0.What can you conclude about the vectors a and b.*/
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "lib.h"

int main()
{
	double **a,**b,**R,X,**Y,**P;//declaring variables
	int m=3,n=1,p=3;
	a=loadtxt("data/a.dat",m,n);//a=[1 0 0]	
	b=loadtxt("data/b.dat",m,n); //b=[0 0 0]
        Y=transpose(a,m,n);//transposing of matrix a
	X=mat_mult(Y,b,1,3,3);//dot product of Y and b
        printf("X=%lf\n",X);
	P=crossProduct(a,b);//cross product of a and b
	print(P,n,m);
	return 0;
}
