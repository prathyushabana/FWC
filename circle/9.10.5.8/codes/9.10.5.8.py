import numpy as np
import matplotlib.pyplot as plt
from coeffs import *

#if using termux
import subprocess
import shlex

#input params
r=3
theta_1=45*np.pi/180
theta_2=180*np.pi/180
theta_3=0*np.pi/180
#Trapezium vertices
A = (r)*np.array([np.cos(theta_2),np.sin(theta_2)])
B =r*np.array([np.cos(theta_3),np.sin(theta_3)])
C =r*np.array([np.cos(theta_1),np.sin(theta_1)])
D =r*np.array([(-np.cos(theta_1)),np.sin(theta_1)])
#print('A=',A)
#print('B=',B)
#print('C=',C)
#print('D=',D)
r=3.00
O =np.array([0,0])
print('O=',O)
#foot of perpendicular
P1=(2.121320340)*np.array([np.cos(theta_2),np.sin(theta_2)])
#print('P1=',P1)
P2=(2.121320340)*np.array([np.cos(theta_3),np.sin(theta_3)])
#print('P2=',P2)
#directional vectors
m1=A-B
m2=B-C
m3=C-D
m4=A-D
m5=O-B
m6=A-P1
m7=B-P2
m8=P2-C
#m9=O-D

#norms
l1=np.linalg.norm(m1)
l2=np.linalg.norm(m2)
l3=np.linalg.norm(m3)
l4=np.linalg.norm(m4)
l5=np.linalg.norm(m5)
#print('OB=',l5)
l6=np.linalg.norm(m6)
l7=np.linalg.norm(m7)
l8=np.linalg.norm(m8)
#l9=np.linalg.norm(m9)
#print('OD=',l9)

angDAP1=np.degrees(np.arccos(np.dot(m4,m6)/(l4*l6)))
angDCP2=np.degrees(np.arccos(np.dot(m3,m8)/(l3*l8)))
angBCP2=np.degrees(np.arccos(np.dot(m2,m8)/(l2*l8)))
print('angDAP1',angDAP1)
print('angDCP2',angDCP2)
print('angBCP2',angBCP2)
#Proof for trapezium is cyclic 
if  round(angDAP1+angDCP2+angBCP2)==180:
    print("Given ABCD is cyclic")
#Generating the line 
xAB = line_gen(A,B)
xBC = line_gen(B,C)
xCD = line_gen(C,D)
xAD = line_gen(A,D)
#xOD = line_gen(O,D)
xDP1 = line_gen(D,P1)
xCP2 = line_gen(C,P2)
xOB = line_gen(O,B)
##Generating the circle
x_circ= circ_gen(O,r)
plt.plot(x_circ[0,:],x_circ[1,:],label='Circle')

#Plotting all lines
plt.plot(xAB[0,:],xAB[1,:],label='AB')
plt.plot(xBC[0,:],xBC[1,:],label='BC')
plt.plot(xCD[0,:],xCD[1,:],label='CD')
plt.plot(xAD[0,:],xAD[1,:],label='AD')
#plt.plot(xOD[0,:],xOD[1,:],label='OD')
plt.plot(xDP1[0,:],xDP1[1,:],linestyle='--', label='DP1')
plt.plot(xCP2[0,:],xCP2[1,:],linestyle='--', label='CP2')	
#Labeling the coordinates
tri_coords = np.vstack((O,A,C,D,B,P1,P2)).T
plt.scatter(tri_coords[0,:], tri_coords[1,:])
vert_labels = ['O','A','C','D','B','P1','P2']
for i, txt in enumerate(vert_labels):
    plt.annotate(txt, # this is the text
                 (tri_coords[0,i], tri_coords[1,i]), # this is the point to label
                 textcoords="offset points", # how to position the text
                 xytext=(5,5), # distance from text to points (x,y)
                 ha='center') # horizontal alignment can be left, right or center

plt.xlabel('$x$')
plt.ylabel('$y$')
plt.legend(loc='best')
plt.grid() # minor
plt.axis('equal')

#if using termux
plt.savefig('/sdcard/Download/codes/circle/9.10.5.8/figs/fig.pdf')
plt.show()





