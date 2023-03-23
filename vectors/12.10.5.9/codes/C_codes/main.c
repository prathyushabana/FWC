/* code by B.Prathyusha (works on termux)
March 23, 2023
Link to license("https://github.com/prathyushabana/FWC/blob/main/LICENSE")
Find the position vector of a point R which
 divides the  line joining two points
P and Q whose position vectors are P =[2 1]
and Q =[1 -3] externally in the ratio 1:2.Also show that P is the midpoint of the linesegment RQ.*/
#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "lib.h"
#define PI 3.14159265359

int main()
{
	double **P,**Q,**R,**X,**Y;
	int m=2,n=1;
	P=loadtxt("p.dat",m,n);	//P=[2 1]	
	Q=loadtxt("q.dat",m,n); //Q=[1 -3]
	X=mult_int(2,P,m,n);//X=2*P
	Y=linalg_sub(Q,X,m,n);//Y=Q-2*P
	R=mult_int(-1,Y,m,n);//R=(Q-2*P)*(-1)
	save_R(R,m,n);
	
	return 0;
}
