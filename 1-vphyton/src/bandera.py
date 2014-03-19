from visual import *
from lector import *
from curvas import *
from subrutinas import *

lista0=[]
lista1=[]

def P_bandera(l1,l2,t,s):
    h=Bezier(l1,t)
    r=Bezier(l2,t)
    return (1-s)*h+s*r

def u_bandera(l1,l2,t,s):
    return norm(P_bandera(l1,l2,t+.001,s)-P_bandera(l1,l2,t,s))

def devs_bandera(l1,l2,t,s):
    return norm(P_bandera(l1,l2,t,s+.001)-P_bandera(l1,l2,t,s))

def w_bandera(l1,l2,t,s):
    return norm(cross(u_bandera(l1,l2,t,s),devs_bandera(l1,l2,t,s)))


def tela(c,u,v,w,esc,h,a,colb):
    auxh=h/8.
    auxa=a/4.
    
    p0=c
    p1=p0 - v*esc*auxa + w*esc*auxh - u*esc*auxh
    p2=p0 - v*esc*auxa*3 - w*esc*auxh + u*esc*auxh
    p3=p0 - v*esc*a - u*esc*auxh
    lista0=[p0,p1,p2,p3]
    
    q0=c - w*esc*h
    q1=p0 - v*esc*auxa + w*esc*auxh + u*esc*auxh - w*esc*h
    q2=p0 - v*esc*auxa*3 - w*esc*auxh - u*esc*auxh - w*esc*h
    q3=p0 - v*esc*a + u*esc*auxh - w*esc*h
    lista1=[q0,q1,q2,q3]
    
    #Suelo
    t0=0.
    t1=1.
    s0=0.
    s1=1.
    npuntost=11
    npuntoss=1
    inct=(t1-t0)/npuntost
    incs=(s1-s0)/npuntoss

    listap=[]
    listan=[]
    listap1=[]
    listan1=[]
    s=s0
    while s<s1+incs:
        filap=[]
        filan=[]
        filap1=[]
        filan1=[]
        t=t0
        while t<t1+inct:
            filap+=[P_bandera(lista0,lista1,t,s)]
            filan+=[w_bandera(lista0,lista1,t,s)]
            t+=inct
        listap+=[filap]
        listan+=[filan]
        listap1+=[filap1]
        listan1+=[filan1]
        s+=incs
        
    faces(pos=triangular(listap),normal=triangular(listan),color=colb)


def bandera(c,u,v,w,esc,h,g,hb,ab,colposte,colbandera):
    tela(c+w*h,u,v,w,1,2,4,colbandera)
    cylinder(pos=c,color=colposte,axis=(0,h,0), radius=g)

#bandera(vector(0,0,0),vector(1,0,0),vector(0,0,1),vector(0,1,0),1,15,.15,2,4,color.white,color.green)

