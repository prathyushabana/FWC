#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "lib.h"
#define PI 3.14159265359
/* code by B.Prathyusha (works on termux)
March 26, 2023
Link to license("https://github.com/prathyushabana/FWC/blob/main/LICENSE")
If the non-parallel sides of a trapezium are equal,prove that it is cyclic.*/

int main()
{	
	//Declaring variables
	double r=3;//radius of circle
	double **A,**B,**C,**D,**K,**P1,**P2;
	double **m1,**m2,**m3,**m4,**m5,**m6,**m7,**m8,**transofm4,**transofm3,**transofm2,f1,f2,f3,f4,f5,f6,f7,f8,angDAP1,angDCP2,angBCP2,angleDAP1,angleDCP2,angleBCP2;
	int m=2,n=1,p=2,div2,mult2;
        double mult1,div1,div3,mult3;
	
	//Points
	A=np_array(r*cos(PI),r*sin(PI));//A=r*[cos(180),sin(180)]
	B=np_array(r*cos(0),r*sin(0));//B=r*[cos(0),sin(0)]
	save(A,m,n,"data/A.dat");
	save(B,m,n,"data/B.dat");
        C=np_array(r*cos(PI/4),r*sin(PI/4));//C=r*[cos(45),sin(45)]
        save(C,m,n,"data/C.dat");
        D=np_array((-r*cos(PI/4)),r*sin(PI/4));//D=[-r*cos(45),r*sin(45)]
        save(D,m,n,"data/D.dat");
	K=loadtxt("data/K.dat",m,n);
        P1=np_array(2.1*cos(PI),2.1*sin(PI));////P1=2.1*[cos(180),sin(180)]
        save(P1,m,n,"data/P1.dat");
        P2=np_array(2.1*cos(0),2.1*sin(0));//P2=2.1*[cos(0),sin(0)]
        save(P2,m,n,"data/P2.dat");
	
	//directional vectors
	m1=linalg_sub(A,B,m,n);
	m2=linalg_sub(B,C,m,n);
	m3=linalg_sub(C,D,m,n);
	m4=linalg_sub(A,D,m,n);
        m5=linalg_sub(K,B,m,n);
        m6=linalg_sub(A,P1,m,n);
        m7=linalg_sub(B,P2,m,n);
        m8=linalg_sub(P2,C,m,n);
	
	//transpose of directional vector
	transofm4=transpose(m4,m,n);
	transofm3=transpose(m3,m,n);
        transofm2=transpose(m2,m,n);
	//norms
	f1=linalg_norm(m1,m);
	f2=linalg_norm(m2,m);
	f3=linalg_norm(m3,m);
	f4=linalg_norm(m4,m);
        f5=linalg_norm(m5,m);
        f6=linalg_norm(m6,m);
        f7=linalg_norm(m7,m);
        f8=linalg_norm(m8,m);

	//ANGLE DAP1
	mult1=matmul_1(transofm4,m6,n,m,p);
        printf("mult1=%lf \n",mult1);
	div1=mult1/(f4*f6);
	angDAP1=acos(div1);
        angleDAP1=round(degrees(angDAP1));
        printf("angleDAP1=%lf\n",angleDAP1);

        //ANGLE DCP2
	mult2=matmul_1(transofm3,m8,n,m,p);
	div2=mult2/(f3*f8);
	angDCP2=acos(div2);
        angleDCP2=round(degrees(angDCP2));
        printf("angleDCP2=%lf\n",angleDCP2);


        //ANGLE BCP2
	mult3=matmul_1(transofm2,m8,n,m,p);
	div3=mult3/(f2*f8);
	angBCP2=acos(div3);
        angleBCP2=round(degrees(angBCP2));
        printf("angleBCP2=%lf\n",angleBCP2);



	//Proof for given trapezium  is  cyclic
	if (angleDAP1+angleDCP2+angleBCP2 == 180)
	{
    		printf("Given ABCD is cyclic \n");
    	}	
    	return 0;
}

