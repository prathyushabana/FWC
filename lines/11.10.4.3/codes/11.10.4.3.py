import numpy as np 
import mpmath as mp 
import math as ma 
import matplotlib.pyplot as plt 
from numpy import linalg as LA  
def line_gen(m,A,p1,p2):  
  len = 10  
  dim = A.shape[0]  
  x_AB = np.zeros((dim,len))  
  lam_1 = np.linspace(p1,p2,len)  
  for i in range(len):  
    temp1 = A + lam_1[i]*m  
    x_AB[:,i]= temp1.T  
  return x_AB 
#Inputs
A=  np.array(([3,2])) 
B= np.array(([3,0]))
C= np.array(([0,-2])) 
D=  np.array(([-2,3]))     
#Direction vector and normal vector
m=np.array(([3,2]))                                                             
p=np.array(([0,1],[-1,0]))                            
n=A@p 
m=D@p                                   
print(n) 
print(m)  
#Generating the lines 
p1=-4 
p2=2 
x_AB = line_gen(n,B,p1,p2) 
x_CD = line_gen(m,C,p1,p2)  
#Plotting the lines 
plt.plot(x_AB[0,:],x_AB[1,:],label='(-2 3)x=6') 
plt.plot(x_CD[0,:],x_CD[1,:],label='(-3 -2)x=6')  
#Labeling the coordinates 
tri_coords = np.vstack((B,C)).T 
plt.scatter(tri_coords[0,:], tri_coords[1,:]) 
vert_labels = ['A''(3,0) ','B''(0,-2)'] 
for i, txt in enumerate(vert_labels): 
    plt.annotate(txt,(tri_coords[0,i], tri_coords[1,i]), 
                 textcoords="offset points", 
                 xytext=(0,-19),
                 ha='center')
plt.xlabel('x',color='#1c2833') 
plt.ylabel('y',color='#1c2833')  
plt.legend(loc='upper left')
plt.grid() 
plt.axis('equal') 
plt.savefig('/sdcard/Download/codes/lines/11.10.4.3/figs/fig.pdf') 

plt.show()

