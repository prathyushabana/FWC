//Function declaration
double quadratic(double coefa,double coefb,double constant);
//Defining the function for finding the roots of equation
double quadratic(double coefa,double coefb,double constant)
{
  double d,r1,r2;
  double b;
     d= (coefb*coefb) - (4*coefa*constant);//claculating the discriminant
     if (d>0)
     {
          r1 = -coefb+sqrt (d) / (2*coefa);
          r2 = -coefb-sqrt (d) / (2*coefa);
          printf ("The real roots = %lf,%lf \n", r1, r2);
     }      
     else if (d==0)
     {
          r1 = -coefb/(2*coefa);
          r2 = -coefb/(2*coefa);
          printf ("roots are equal =%lf, %lf \n", r1, r2);
     }
     else
          printf("Roots are imaginary");
        if(r1>0)
        {
          b=r1;
        }
        if(r2>0)
        {
          b=r2;
        }
        return b;  
}
