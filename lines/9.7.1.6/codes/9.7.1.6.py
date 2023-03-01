import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as LA
import math
def line_gen(A,B):
  len =10
  dim = A.shape[0]
  x_AB = np.zeros((dim,len))
  lam_1 = np.linspace(0,1,len)
  for i in range(len):
    temp1 = A + lam_1[i]*(B-A)
    x_AB[:,i]= temp1.T
  return x_AB

d = 7
theta = np.pi/2.5
B = np.array([-1,0])
C = np.array([d,0])
A = np.array([5*np.cos(theta) , 5*np.sin(theta)])
E =np.array(([8.5,6])) 
D = np.array(([4,0]))  
#Directional vectors
m_1=A-B
m_2=C-B
m_3=C-A
m_4=D-A
m_5=D-E
m_6=A-E

f1 = np.linalg.norm(A-B)
f2 = np.linalg.norm(A-C)
e2 = np.linalg.norm(A-D)
e3 = np.linalg.norm(A-E)
dp1 = np.dot(m_1/f1,m_3/f2)
dp2 = np.dot(m_4/e2,m_6/e3)
f3 = np.linalg.norm(D-E)
f4 = np.linalg.norm(B-C)
angleBAC=np.degrees(np.arccos(np.dot(m_1,m_3)/(f1*f2)))
angleDAE=np.degrees(np.arccos(np.dot(m_4,m_6)/(e2*e3)))
#proving the triangles are congruent
if (m_1.all()==m_4.all()) and (round(dp1) == round(dp2)) and (m_3.all()==m_6.all()):
 print("(i)∆ ABC ≅ ∆ ADE")
if round(f3)==round(f4):
   print("(ii) BC=DE")

#generating lines
x_AB = line_gen(A,B)
x_CB = line_gen(C,B)
x_CA = line_gen(C,A)
x_DA = line_gen(D,A)
x_DE = line_gen(D,E)
x_CE = line_gen(C,E)
x_AE = line_gen(A,E)
#Plotting all lines
plt.plot(x_AB[0,:],x_AB[1,:])
plt.plot(x_CB[0,:],x_CB[1,:])
plt.plot(x_CA[0,:],x_CA[1,:])
plt.plot(x_DA[0,:],x_DA[1,:])
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
plt.savefig('/sdcard/Download/codes/lines/9.7.1.6/fig/fig.pdf') 
plt.show()
