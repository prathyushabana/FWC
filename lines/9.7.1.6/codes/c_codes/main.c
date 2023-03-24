#include<stdio.h>
#include<stdlib.h>
#include <math.h>
#include "lib.h"
#define PI 3.14159265359
/* code by B.Prathyusha (works on termux)
March 24, 2023
Link to license("https://github.com/prathyushabana/FWC/blob/main/LICENSE")
In the figure,AC=AE,AB=AD and angleBAD=angleEAC.Show that BC=DE.*/

int main()
{
	//Declaring variables
	int a=8,c=5,b=7,m=2,n=1,p=2;
        double R,Y;
	double S,X,**M,a1,a2,a3,a4;
	double **A,**B,**C,**D,**E,**e1,**Z;
	double **m1,**m2,**m3,**m4,**m5,**m6,f1,f2,f3,f4,f5,f6;
	double **transofm1,**transofm2,**transofm3,**transofm4,**transofm5,**transofm6,mult1,mult2,div1,div2,mult3,mult4;
	int div3,div4;
	double  angleBCA,angleACE,angleC,angleBAC,angleDAE,angleDAC,angleCAE,angDAE,angBAC;
	
	
	//load text from data file 
	B=loadtxt("data/B.dat",2,1);		
	C=loadtxt("data/C.dat",2,1);
	e1=loadtxt("data/e1.dat",2,1);
        //Defining the vertex points
        A=np_array(c*cos(PI/3),c*sin(PI/3));//A=c*[cos(PI/3),sin(PI/3)]
        save(A,m,n,"data/A.dat");
        S=2*c*sin(PI/6);
        D=mult_double(S,e1, m, n); //D=(2*c*sin(PI/6))*e1
        save(D,m,n,"data/D.dat");




	//Defining angleBCA
        R=(pow(a,2)+pow(b,2)-pow(c,2))/(2*a*b);
        angleBCA=acos(R);
       
        //Defining the angleACE
        angleACE=(PI/2)-(PI/6);
      
	X=angleBCA+angleACE; //x=angleBCA+angleACE
        angleC=(PI)-(X); // angleC=180-(angleBCA+angleACE)
      
        Y=2*b*sin(PI/6);
        M=np_array(cos(angleC),sin(angleC));
        Z=mult_double(Y,M,m,n);//Z=C+2*b*sin(PI/6)
        //Defining E point
        E=linalg_add(C,Z,m,n);
        save(E,m,n,"data/E.dat");
       
	
        //Directional vectors
	m1=linalg_sub(B,A,m,n);
	m2=linalg_sub(C,B,m,n);
	m3=linalg_sub(C,A,m,n);
	m4=linalg_sub(D,A,m,n);
	m5=linalg_sub(D,E,m,n);
        m6=linalg_sub(E,A,m,n);

	
	//Transpose matrices
	transofm1=transpose(m1,m,n);
	transofm2=transpose(m2,m,n);
	transofm3=transpose(m3,m,n);
	transofm4=transpose(m4,m,n);
        transofm5=transpose(m5,m,n);
        transofm6=transpose(m6,m,n);
      
	
	
	//Norms of directional vectors
	f1=linalg_norm(m1,m);
       	printf("f1=%lf \n",f1);
	f2=linalg_norm(m2,m);
	f3=linalg_norm(m3,m);
        printf("f3=%lf \n",f3);
	f4=linalg_norm(m4,m);
        printf("f4=%lf \n",f4);
	f5=linalg_norm1(m5,m);
	f6=linalg_norm(m6,m);

	
	
	//angleBAC
	mult1=matmul_1(transofm1,m3,1,2,2);
        div1=mult1/(f1*f3);
        angleBAC=acos(div1);
	angBAC=round(degrees(angleBAC));
        printf("angleBAC=%lf\n",angBAC);
        
	//angleDAE
	mult2=matmul_1(transofm4,m6,1,2,2);
        div2=mult2/(f4*f6);
	angleDAE=acos(div2);
	angDAE=round(degrees(angleDAE));
        printf("angleDAE=%f\n",angDAE);
	
	if (f1=f4)
	{
		if( angBAC=angDAE)
		{
			if(f3=f6){
		printf("(i) ∆ ABC ≅ ∆ ADE \n");
		printf("(ii) BC=DE \n");
	}}}
	return 0;
}
	

