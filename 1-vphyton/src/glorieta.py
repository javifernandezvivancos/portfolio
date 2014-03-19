from visual import *
from lector import *
from curvas import *
from subrutinas import *
from banco import *

def glorieta(c,u,v,w,r,d,h,h2,nlados,col):
    r2=r-d
    listav=[]
    angini=pi/4
    angg=2*pi/nlados/2
    i=0
    while i<=nlados:
        p=c+(r+2*d)*vector(cos(angini+angg*i),0,sin(angini+angg*i))
        listav+=[p]
        i=i+1
    i=0
    while i<=nlados:
        p=c+r*vector(cos(angini+angg*i),h2/r,sin(angini+angg*i))
        listav+=[p]
        i=i+1
    i=0
    while i<=nlados:
        p=c+(r+d)*vector(cos(angini+angg*i),h2/(r+d),sin(angini+angg*i))
        listav+=[p]
        i=i+1
    i=0
    while i<=nlados:
        p=c+(r+d)*vector(cos(angini+angg*i),h/(r+d),sin(angini+angg*i))
        listav+=[p]
        i=i+1
    i=0
    while i<=nlados:
        p=c+(r-d)*vector(cos(angini+angg*i),h/(r-d),sin(angini+angg*i))
        listav+=[p]
        i=i+1
    i=0
    while i<=nlados:
        p=c+r2*vector(cos(angini+angg*i),h/2/r2,sin(angini+angg*i))
        listav+=[p]
        i=i+1
    listav+=[c+vector(0,h/2,0)]
    listac=[]
    listacol=[]
    i=0
    n=nlados+1
    while i<nlados:
        i1=i
        i2=i1+1
        cara1=[i1,i1+n,i2+n,i2]
        cara2=[i1+n,i1+n*2,i2+n*2,i2+n]
        cara3=[i1+n*2,i1+n*3,i2+n*3,i2+n*2]
        cara4=[i1+n*3,i1+n*4,i2+n*4,i2+n*3]
        cara5=[i1+n*4,i1+n*5,i2+n*5,i2+n*4]
        cara6=[i1+n*5,n*6,i2+n*5]
        listac+=[cara1,cara2,cara3,cara4,cara5,cara6]
        listacol+=[col,col,col,col,col,col]
        i+=1
    dibujar(listav,listac,pon_vectores_c(listav,listac),col,2,1,0)
    
    listavaux=[listav[0],listav[1],listav[2],listav[3],listav[4],listav[5],listav[6],listav[7],listav[8]]
    listavaux+=[listav[0]-w*h,listav[1]-w*h,listav[2]-w*h,listav[3]-w*h,listav[4]-w*h,listav[5]-w*h,listav[6]-w*h,listav[7]-w*h,listav[8]-w*h]
    cara0=[0,1,10,9]
    cara1=[1,2,11,10]
    cara2=[2,3,12,11]
    cara3=[3,4,13,12]
    cara4=[4,5,14,13]
    cara5=[5,6,15,14]
    cara6=[6,7,16,15]
    cara7=[7,8,17,16]
    listacaux=[cara0,cara1,cara2,cara3,cara4,cara5,cara6,cara7]
    dibujar(listavaux,listacaux,pon_vectores_c(listavaux,listacaux),col,2,1,0)

    Uaux=u
    Vaux=v
    angg=2*pi/nlados/2
    angini=pi/4 + angg/2
    listahuecos=[]
    i=0
    while i<nlados:
        q=c+vector(0,h/2,0)
        p=c+(r2*.7)*vector(cos(angini+angg*i),h/2/(r2*.7),sin(angini+angg*i))
        Vaux=norm(p-q)
        Uaux=norm(cross(Vaux,w))
        if i==0 or i==7 or i==2 or i==5:
            banco(p,-Uaux,Vaux,w,5,2.5,2,0.875,.5,.1,(.7,.8,.5))
        
        #sphere(pos=p,radius=0.3,color=color.red)
        i=i+1
    return listav


def ramal(c,u,v,w,ini,a,d,h,h2,l,col):
    listav=[]
    listac=[]
    listacol=[]
    a2=a-d
    p4=c+(a-d)*vector(cos(ini),h/(a-d),sin(ini))
    p3=p4+2*d*v
    p2=p3-2*d*w
    p1=p2-d*v
    p5=c+a2*vector(cos(ini),h/2/a2,sin(ini))
    p=p1-h2*w+2*d*v
    p6=p5-a*v
    listav+=[p,p1,p2,p3,p4,p5,p6,p+l*u,p1+l*u,p2+l*u,p3+l*u,p4+l*u,p5+l*u,p6+l*u]
    cara1=[0,7,8,1]
    cara2=[1,8,9,2]
    cara3=[2,9,10,3]
    cara4=[3,10,11,4]
    cara5=[4,11,12,5]
    cara6=[5,12,13,6]
    listac+=[cara1,cara2,cara3,cara4,cara5,cara6]
    listacol+=[col,col,col]
    dibujar(listav,listac,pon_vectores_c(listav,listac),col,2,1,0)

    listavaux=[listav[0],listav[7]]
    listavaux+=[listav[0]-w*h,listav[7]-w*h]
    cara0=[0,2,3,1]
    listacaux=[cara0]
    dibujar(listavaux,listacaux,pon_vectores_c(listavaux,listacaux),col,2,1,0)
    
    return listav

def union_ramales_glo(U,V,W,vglorieta,vramalh,vramalv,lramalh,lramalv,hglorieta,rglorieta):
    listavaux=[]
    listacaux=[]

    p1=vramalh[5]
    p2=vramalh[6]
    p3=vramalv[13]
    p4=vramalv[12]
    p5=vramalh[13]-lramalh/1.25*U
    listavaux=[p1,p2,p3,p4,p5]
    cara1=[0,1,2,3]
    cara2=[4,2,1]
    listacaux=[cara1,cara2]
    dibujar(listavaux,listacaux,pon_vectores_c(listavaux,listacaux),color.white,2,1,0)
    # Tapas laterales
    #Horizontal
    p0=vramalh[7]
    p1=vramalh[8]
    p2=vramalh[9]
    p3=vramalh[10]
    p4=vramalh[11]
    p5=vramalh[12]
    p6=vramalh[13]
    p7=vector(p0[0],p0[1],p6[2])
    p8=p0-W*8
    p9=p7-W*8
    listavaux=[p0,p1,p2,p3,p4,p5,p6,p7,p8,p9]
    cara1=[7,6,5,0]
    cara2=[0,5,1]
    cara3=[5,4,1]
    cara4=[1,4,3,2]
    cara5=[0,8,9,7]
    listacaux=[cara1,cara2,cara3,cara4,cara5]

    #Vertical
    p0=vramalv[0]
    p1=vramalv[1]
    p2=vramalv[2]
    p3=vramalv[3]
    p4=vramalv[4]
    p5=vramalv[5]
    p6=vramalv[6]
    p7=p6-hglorieta/2*W
    p8=p0-W*8
    p9=p7-W*8
    listavaux+=[p0,p1,p2,p3,p4,p5,p6,p7,p8,p9]
    cara1=[10,15,16,17]
    cara2=[10,11,15]
    cara3=[12,14,15]
    cara4=[12,13,14]
    cara5=[10,17,19,18]
    cara6=[18,19,9,8]
    listacaux+=[cara1,cara2,cara3,cara4,cara5,cara6]
    dibujar(listavaux,listacaux,pon_vectores_c(listavaux,listacaux),color.white,2,1,0)

    #Curva union ramales
    p1=vramalv[6]
    p2=vramalv[13]
    p3=vramalh[13]-lramalh*U
    p4=vramalh[13]

    listaunionramales=[p1+rglorieta/2*V,p2+rglorieta/2*V,p3+rglorieta/2*V,p4+rglorieta/2*V]
    listaunionramales1=[p1,p2,p3,p4]
    listaunionramales2=[p1-hglorieta/2*W,p2-hglorieta/2*W,p3-hglorieta/2*W,p4-hglorieta/2*W]

    listareglar1=[]
    listareglar2=[]
    def Punionramales(t,s):
        h=Bezier(listareglar1,t)
        r=Bezier(listareglar2,t)
        return (1-s)*h+s*r

    def uPunionramales(t,s):
        return norm(Punionramales(t+.001,s)-Punionramales(t,s))

    def devsunionramales(t,s):
        return norm(Punionramales(t,s+.001)-Punionramales(t,s))

    def wPunionramales(t,s):
        return norm(cross(uPunionramales(t,s),devsunionramales(t,s)))

    # Suelo
    listareglar1=listaunionramales
    listareglar2=listaunionramales1
    t0=0.
    t1=1.
    s0=0.
    s1=1.
    npuntost=100
    npuntoss=2
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
            filap+=[Punionramales(t,s)]
            filan+=[wPunionramales(t,s)]
            t+=inct
        listap+=[filap]
        listan+=[filan]
        s+=incs
    faces(pos=triangular(listap),normal=triangular(listan),color=color.white)

    #Lateral
    listareglar1=listaunionramales1
    listareglar2=listaunionramales2
    t0=0.
    t1=1.
    s0=0.
    s1=1.
    npuntost=100
    npuntoss=2
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
            filap+=[Punionramales(t,s)]
            filan+=[wPunionramales(t,s)]
            t+=inct
        listap+=[filap]
        listan+=[filan]
        s+=incs
    faces(pos=triangular(listap),normal=triangular(listan),color=color.white)
