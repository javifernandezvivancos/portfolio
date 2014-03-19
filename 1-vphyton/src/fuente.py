from visual import *
from bezier import *
from subrutinas import *

def fuente(radio,nChorros,O,ejex,ejey,ejez,col):
    #rutinas necesarias
    def P(t,s):
        R=Bez(P0,P1,P2,P3,t)
        r=R[0]
        return vector(r*cos(s),R[1],r*sin(s))
    def u(t,s):
        return norm(P(t+.01,s)-P(t,s))

    def ders(t,s):
        return norm(P(t,s+.01)-P(t,s))

    def w(t,s):
        return norm(cross(u(t,s),ders(t,s)))

    def colocar(lista, C, u, v, w, escx, escy, escz):
        lista2=[]
        for Q in lista:
            R=C+escx*Q[0]*u + escy*Q[1]*w + escz*Q[2]*v
            lista2+=[R]
        return lista2

    #cuerpo de la fuente, por revolucion
    P0 = vector(0.1*radio,0,0)
    P1 = vector(0.2*radio,0.3*radio,0)
    P2 = vector(-0.4*radio,0,0)
    P3 = vector(1.22*radio,0.4*radio,0)
    perfil = curve()  
    
    t=0
    while t<=1:
        Q=Bez(P0,P1,P2,P3,t)
        perfil.append(pos=Q)
        t+=.01

    listap=[]
    listan=[]
    t0=0.
    t1=1.
    s0=0.
    s1=2*pi

    npuntost=20
    npuntoss=20

    inct=(t1-t0)/npuntost
    incs=(s1-s0)/npuntoss

    s=s0
    while s<=s1:
        filap=[]
        filan=[]
        t=t0
        while t<=t1:
            filap+=[P(t,s)]
            filan+=[w(t,s)]
            t+=inct
        listap+=[filap]
        listan+=[filan]
        s+=incs
    lista1=triangular(listap)
    lista2=triangular(listan)

    perfil.visible=0
    faces(pos = colocar(lista1,O,ejex,ejez,ejey,1,1,1), normal=colocar(lista2,O,ejex,ejez,ejey,1,1,1), color=col)   

    #agua
    cylinder(pos=O+0.3*radio*ejey,axis=0.001*ejey,radius=0.79*radio,color=color.blue)

    #pitorro de los chorros
    sphere(pos=O+0.3*radio*ejey,radius=0.05*radio,color=col)
    
    #chorros
    P0= O+0.3*radio*ejey
    perfil = curve(color=color.blue)  

    ang= 2*pi/nChorros
    i=0
    while i<nChorros:
        P3= O + 0.6*radio*cos(i*ang)*ejex + 0.6*radio*sin(i*ang)*ejez + 0.3*radio*ejey
        P1= O + (P3-P0)+ 1.5*radio*ejey
        P2= O + (P3-P0)+ 0.001*radio*ejey
        t=0
        while t<=1:
            Q=Bez(P0,P1,P2,P3,t)
            perfil.append(pos=Q)
            t+=.01
        i= i+1    

#O=vector(0,0,0)
#ejex=vector(1,0,0)
#ejey=vector(0,1,0)
#ejez=vector(0,0,1)
#fuente(50,10,O,ejex,ejey,ejez,color.green)
