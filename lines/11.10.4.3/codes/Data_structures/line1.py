import cmath
import matplotlib.pyplot as plt
import numpy as np
import mpmath as mp
import math as ma
from numpy import linalg as LA
import math
import numpy as np
from sympy import *  
A= np.loadtxt('data/A.dat',dtype='double')
B= np.loadtxt('data/B.dat',dtype='double')
C= np.loadtxt('data/C.dat',dtype='double')
D= np.loadtxt('data/D.dat',dtype='double')	
#generating a line
def line_gen(A,B):
    len=10
    dim = A.shape[0]
    x_AB = np.zeros((dim,len))
    lam_1 = np.linspace(0,1,len)
    for i in range(len):
        temp1 = A + lam_1[i]*(B-A)
        x_AB[:,i] = temp1.T
    return x_AB
x = np.linspace(-5,5,100)
x_AB=line_gen(A,B)
x_CD=line_gen(C,D)
#plotting the lines
plt.plot(x_AB[0,:],x_AB[1,:],label='(2 -3)x=-6')
plt.plot(x_CD[0,:],x_CD[1,:],label='(-3 2)x=-6')
sqr_vert = np.vstack((A,B,C,D)).T
plt.scatter(sqr_vert[0,:],sqr_vert[1,:])
vert_labels = ['(3,0)','(0,-2)','(-2,0)','(0,3)']

for i, txt in enumerate(vert_labels):
    plt.annotate(txt,
            (sqr_vert[0,i], sqr_vert[1,i]),
            textcoords = 'offset points',
            xytext = (0,10),
            ha='center')
plt.xlabel('x', color='#1C2833')
plt.ylabel('y', color='#1C2833')
plt.legend(loc='upper left')
plt.grid()                                      
plt.axis('equal')
plt.show()
