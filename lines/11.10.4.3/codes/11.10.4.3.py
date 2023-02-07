import matplotlib.pyplot as plt
import numpy as np
import mpmath as mp
import math as ma
from matplotlib import pyplot as plt
from numpy import linalg as LA
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
#intercepts
A=np.array(([3,0]))
B=np.array(([0,-2]))
C=np.array(([-2,0]))
D=np.array(([0,3]))
x_AB=line_gen(A,B)
x_CD=line_gen(C,D)
#Directional vector and normal vector
m1=np.array(([3,2]))
m2=np.array(([-2,-3]))
p=np.array(([0,1],[-1,0]))
n1=p@m1
n2=p@m2
print(n1)
print(n2)
#plotting the lines
plt.plot(x_AB[0,:],x_AB[1,:],label='(-2 3)x=-6')
plt.plot(x_CD[0,:],x_CD[1,:],label='(3 -2)x=-6')
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
plt.savefig('/sdcard/Download/codes/lines/11.10.4.3/figs/fig.pdf')
plt.show()

