from visual import *
from lector import *
from curvas import *
from subrutinas import *
from random import *

def P_arena(l,t,s):
    lis=[]
    for F in l:
        lis+=[CRom(F,t)]
    return CRom(lis,s)

def u_arena(l,t,s):
    return norm(P_arena(l,t+.001,s)-P_arena(l,t,s))

def ders_arena(l,t,s):
    return norm(P_arena(l,t,s+.001)-P_arena(l,t,s))

def w_arena(l,t,s):
    return norm(cross(u_arena(l,t,s),ders_arena(l,t,s)))

def poner_arena(u,v,w,p0,p1,p2,p3,ha,hmax,col):
    lista=[]
    npuntosf=30
    nfilas=30
    u=norm(p0-p3)
    v=norm(p2-p3)
    desh=mag(p0-p3)/(npuntosf-2-1)
    desv=mag(p2-p3)/(npuntosf-2-1)
    pini=p3-desh*u-desv*v

    i=0
    while i<nfilas:
        fila=[]
        j=0
        while j<npuntosf:
            Q=pini+j*desh*u
            if j>1 and j<npuntosf-2 and i>1 and i<nfilas-2:
                Q+=vector(0,2*hmax*random()-hmax,0)
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
            h=P_arena(lista,t,s)
            if h[2]<p1[2] and h[0]>0:
                h[1]=0
            filap+=[h]
            filan+=[w_arena(lista,t,s)]
            t+=inct
        listap+=[filap]
        listan+=[filan]
        s+=incs
    faces(pos=triangular(listap),normal=triangular(listan),color=col)

    #
    arena0=p0
    arena1=p1+w*0.18
    arena2=p2
    arena3=p3
    arena4=arena0-w*ha*3
    arena5=vector(arena1[0],arena4[1],arena1[2])
    arena6=vector(arena2[0],arena4[1],arena2[2])
    arena7=vector(arena3[0],arena4[1],arena3[2])
    
    listavarena=[arena0,arena1,arena2,arena3,arena4,arena5,arena6,arena7]
    cara0=[4,5,1,0]
    cara1=[5,6,2,1]
    cara2=[6,7,3,2]
    cara3=[0,3,7,4]
    cara4=[4,7,6,5]
    listacarena=[cara0,cara1,cara2,cara3,cara4]
    dibujar(listavarena,listacarena,pon_vectores_c(listavarena,listacarena),col,2,1,0)
    #convex(pos=listavarena,color=(.7,.5,0))
