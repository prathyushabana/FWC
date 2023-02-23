import math
import numpy as np
import matplotlib.pyplot as plt
from numpy import linalg as  LA
import subprocess
import shlex

#construction of triangle
r=3
theta1= np.pi/3
theta2=np.pi/4

A=r*np.array(([np.cos(theta1),np.sin(theta2)]))
B=np.array(([0,0]))
C=np.array(([4,0]))
D=np.array(([3,0]))
E=np.array([4.1,4])

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
#generating all lines
X_AB=line_gen(A,B)
X_CB=line_gen(C,B)
X_CA=line_gen(C,A)
X_DA=line_gen(D,A)
X_DE=line_gen(D,E) 
X_CE=line_gen(C,E)
X_AE=line_gen(A,E)
#plotting all lines
plt.plot(X_AB[0,:],X_AB[1,:])
plt.plot(X_CB[0,:],X_CB[1,:])
plt.plot(X_CA[0,:],X_CA[1,:])
plt.plot(X_DA[0,:],X_DA[1,:])
plt.plot(X_DE[0,:],X_DE[1,:])
plt.plot(X_CE[0,:],X_CE[1,:])
plt.plot(X_AE[0,:],X_AE[1,:])

#Direction vectors
m_1 = A-B
m_2 = C-B
m_3 = C-A
m_4 = D-A
m_5 = D-E
m_6 = A-E
#finding angles

f1 = np.linalg.norm(A-B)
f2 = np.linalg.norm(A-C)
e2 = np.linalg.norm(A-D)
e3 = np.linalg.norm(A-E)
dp1 = np.dot(m_1/f1,m_3/f2)
dp2 = np.dot(m_4/e2,m_6/e3)
f3 = np.linalg.norm(D-E)
f4 = np.linalg.norm(B-C)
#proving the triangles are congruent
if (m_1.all()==m_4.all()) and (round(dp1) == round(dp2)) and (m_3.all()==m_6.all()):
	print("(i)∆ ABC ≅ ∆ ADE")
if round(f3)==round(f4):
   print("(ii) BC=DE")  
#Labeling the coordinates
tri_coords =np.vstack((B,C,D,A,E)).T

plt.scatter(tri_coords[0,:],tri_coords[1,:])
vert_labels = ['B','C','D','A','E']
for i,txt in enumerate(vert_labels):
	plt.annotate(txt,
			(tri_coords[0,i],tri_coords[1,i]),
			textcoords="offset points",
			xytext=(0,10),
			ha='center')

plt.xlabel('$X$')
plt.ylabel('$Y$')
plt.grid()
plt.axis('equal')

plt.show()
plt.savefig('/sdcard/Download/codes/lines/9.7.1.6/fig/fig.pdf')
