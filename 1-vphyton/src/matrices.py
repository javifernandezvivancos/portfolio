from visual import *
from numpy import *

def proyecta(P,u,Q,v1,v2):
    B=array([[u[0],v1[0],v2[0]],[u[1],v1[1],v2[1]],[u[2],v1[2],v2[2]]])
    if linalg.det(B)<>0:
        A=array([[0,0,0],[0,1,0],[0,0,1]])
        M=dot(B,dot(A,linalg.inv(B)))
        R=Q+vector(transpose(dot(M,transpose(P-Q))))
        return R

def gira(P,Q,w,ang):
    if w[0]==0 and w[2]==0:
        u=vector(1,0,0)
        v=vector(0,0,1)
    else:
        w=norm(w)
        u=norm(vector(-w[2],0,w[0]))
        v=cross(u,w)
    B=array([[u[0],v[0],w[0]],[u[1],v[1],w[1]],[u[2],v[2],w[2]]])
    if linalg.det(B)<>0:
        A=array([[cos(ang),-sin(ang),0],[sin(ang),cos(ang),0],[0,0,1]])
        M=dot(B,dot(A,linalg.inv(B)))
        R=Q+vector(transpose(dot(M,transpose(P-Q))))
        return R


