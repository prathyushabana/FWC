import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA
import math
#local imports
#from line.funcs import *
#from triangle.funcs import *
#from conics.funcs import circ_gen
#from conics.funcs import *
def line_gen(A,B):
  len =10
  dim = A.shape[0]
  x_AB = np.zeros((dim,len))
  lam_1 = np.linspace(0,1,len)
  for i in range(len):
    temp1 = A + lam_1[i]*(B-A)
    x_AB[:,i]= temp1.T
  return x_AB
A= np.loadtxt('data/A.dat',dtype='double') 
B= np.loadtxt('data/B.dat',dtype='double')
C =np.loadtxt('data/C.dat',dtype='double')
D=np.loadtxt('data/D.dat',dtype='double')
E=np.loadtxt('data/E.dat',dtype='double')
#Directional vectors
m_1=B-A
m_2=C-B
m_3=C-A
m_4=D-A
m_5=D-E
m_6=E-A
#generating lines
x_AB = line_gen(A,B)
x_CB = line_gen(C,B)
x_CA = line_gen(C,A)
x_AD = line_gen(A,D)
x_DE = line_gen(D,E)
x_CE = line_gen(C,E)
x_AE = line_gen(A,E)
#Plotting all lines
plt.plot(x_AB[0,:],x_AB[1,:])
plt.plot(x_CB[0,:],x_CB[1,:])
plt.plot(x_CA[0,:],x_CA[1,:])
plt.plot(x_AD[0,:],x_AD[1,:])
plt.plot(x_DE[0,:],x_DE[1,:])
plt.plot(x_CE[0,:],x_CE[1,:])
plt.plot(x_AE[0,:],x_AE[1,:])

#Labeling the coordinates
tri_coords = np.vstack((A,B,C,D,E)).T
#tri_coords = np.vstack((B,C,Q)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['A','B','C', 'D','E']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(5,10), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

plt.xlabel('$x$')
plt.ylabel('$y$')
plt.grid() 
plt.axis('equal')
plt.show()

