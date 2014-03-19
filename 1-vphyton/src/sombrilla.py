from visual import *
from curvas import *
from subrutinas import *

def P_som(l1,l2,t,s):
    h=Bezier(l1,t)
    r=Bezier(l2,t)
    return (1-s)*h+s*r

def u_som(l1,l2,t,s):
    return norm(P_som(l1,l2,t+.001,s)-P_som(l1,l2,t,s))

def devs_som(l1,l2,t,s):
    return norm(P_som(l1,l2,t,s+.001)-P_som(l1,l2,t,s))

def w_som(l1,l2,t,s):
    return norm(cross(u_som(l1,l2,t,s),devs_som(l1,l2,t,s)))


def poner_sombrilla(c,u,v,w,esc,h,r,nlados,col1,col2):
    #palo
    p0=c+w*h
    curve(pos=[c-w*1,p0],radius=0.09*esc,color=color.white)
    sphere(pos=p0,radius=0.09*esc,color=color.white)

    #Calcular puntos
    listas=[]
    r10=r/10.
    r4=r/4.
    
    ug=u
    vg=v
    angg=2*pi/nlados
    i=0
    while i<=nlados+1:
        lista=[p0]
        p1=p0+ ug*r4
        p2=p1+ ug*r4*2 - w*r10/2
        p3=p0+ ug*r - w*r4
        lista+=[p1,p2,p3]
        
        ug=norm(cos(angg*i)*u+sin(angg*i)*v)
        vg=cross(ug,w)
        i=i+1
        listas+=[lista]
    #Dibujar superficies
    i=0
    coloract=col1
    while i<=nlados:
        i2=i+1
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
        s=s0
        while s<s1+incs:
            filap=[]
            filan=[]
            t=t0
            while t<t1+inct:
                filap+=[P_som(listas[i],listas[i2],t,s)]
                filan+=[w_som(listas[i],listas[i2],t,s)]
                t+=inct
            listap+=[filap]
            listan+=[filan]
            s+=incs
            if i%2 == 0:
                coloract=col1
            else:
                coloract=col2
        faces(pos=triangular(listap),normal=triangular(listan),color=coloract)
        i+=1
    
#poner_sombrilla(vector(0,0,0),vector(1,0,0),vector(0,0,1),vector(0,1,0),1,5,4,8,color.white,color.red)




