#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "lib.h"
/* code by B.Prathyusha (works on termux)
March 24, 2023
Link to license("https://github.com/prathyushabana/FWC/blob/main/LICENSE")
Find the equations of the lines, which cutoff intercepts on the axes whose sum and product are 1 and -6 respectively..*/

int main()
{
    int m=2,n=1,p=2;
    double a, b, c, d, sol1, sol2;
    double **A,**B,**C,**D, **e1,**e2,**e11,**e22,**m1,**m2,**n1,**n2,**p1,**p2;
    printf("Enter a: ");
    scanf("%lf", &a);
    printf("Enter b: ");
    scanf("%lf", &b);
    printf("Enter c: ");
    scanf("%lf", &c);

    // calculate the discriminant
    d = (b*b) - (4*a*c);

    // find two solutions
    sol1 = (-b-sqrt(d))/(2*a);
    sol2 = (-b+sqrt(d))/(2*a);
    printf("The solutions are %.2lf and %.2lf\n", sol1, sol2);

    // finding the two b values
    printf("sol1=%.2lf\n", sol1);
    printf("sol2=%.2lf\n", sol2);
   

    // here we are finding a values for two sets of b
    double b1 = 3, b2 = -2;
    double r1 = a + b1 - 1;//finding solution when b1=3
	//printf("r1=%lf\n",r1);
    double r2 = a + b2 - 1;
	//printf("r2=%lf\n",r2);//finding solution when b2=-2
   // printf("%.2lf\n", r1);
   // printf("%.2lf\n", r2);
    e1=loadtxt("data/e1.dat",2,1);		
    e2=loadtxt("data/e2.dat",2,1);
    A=mult_scalar(sol2,e1,2,1); 
    save(A,m,n,"data/A.dat");
    B=mult_scalar(sol1,e2,2,1); 
    save(B,m,n,"data/B.dat");
    e11=loadtxt("data/e11.dat",2,1);
    C=mult_scalar(r2,e11,2,1);
    save(C,m,n,"data/C.dat");
    e22=loadtxt("data/e22.dat",2,1);
    D=mult_scalar(sol2,e22,2,1); 
    save(D,m,n,"data/D.dat");
//finding the directional vector
m1=linalg_sub(A,B,m,n);
print(m1,m,n);
m2=linalg_sub(C,D,m,n);
print(m2,m,n);
p1=loadtxt("data/p1.dat",2,2);
//finding normal vectors
n1=matmul(p1,m1,m,2,1);
//print(n1,m,n);
p2=loadtxt("data/p2.dat",2,2);
n2=matmul(p2,m2,m,2,1);
print(n2,m,n);
return 0;
}
