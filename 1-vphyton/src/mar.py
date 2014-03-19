from visual import *
from lector import *
from curvas import *
from subrutinas import *
from random import *

def P_mar(l,t,s):
    lis=[]
    for F in l:
        lis+=[Bezier(F,t)]
    return Bezier(lis,s)

def u_mar(l,t,s):
    return norm(P_mar(l,t+.001,s)-P_mar(l,t,s))

def ders_mar(l,t,s):
    return norm(P_mar(l,t,s+.001)-P_mar(l,t,s))

def w_mar(l,t,s):
    return norm(cross(u_mar(l,t,s),ders_mar(l,t,s)))

def poner_mar(u,v,w,p0,p1,p2,p3,p4,col):
    lista=[]
    npuntosf=30
    nfilas=30
    u=norm(p0-p3)
    v=norm(p2-p3)
    desh=mag(p3-p0)/(npuntosf-1)
    desv=mag(p2-p3)/(npuntosf-1)
    pini=p3

    i=0
    while i<nfilas:
        fila=[]
        j=0
        while j<npuntosf:
            Q=pini+j*desh*u
            if j>1 and j<npuntosf-1 and i>1 and i<nfilas-1:
                #if (j%3)<>1 or j==1:
                if i%2==0:
                    Q+=vector(0,.5,0)
            fila+=[Q]
            j+=1
        lista+=[fila]
        i+=1
        pini+=desv*v

    t0=0.
    t1=1.
    s0=0.
    s1=1.
    npuntost=20
    npuntoss=20
    inct=(t1-t0)/npuntost
    incs=(s1-s0)/npuntoss
    listap=[]
    listan=[]
    s=s0
    while s<s1+incs:
        if s>s1:
            s=1
        filap=[]
        filan=[]
        t=t0
        while t<t1+inct:
            if t>t1:
                t=1
            filap+=[P_mar(lista,t,s)]
            filan+=[w_mar(lista,t,s)]
            t+=inct
        listap+=[filap]
        listan+=[filan]
        s+=incs
    faces(pos=triangular(listap),normal=triangular(listan),color=col)

#poner_mar(vector(1,0,0),vector(0,0,1),vector(0,1,0),vector(10,0,10),vector(10,0,-10),vector(-10,0,-10),vector(-10,0,10),vector(-10,0,10),color.blue)
