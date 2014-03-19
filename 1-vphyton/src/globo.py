from visual import*
from bezier import*
from subrutinas import *

def globo(h,nCuerdas,O,U,W,V,col1,col2,col3):
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
        
    #cuerpo de la cesta, por revolucion
    P0 = 0.1*h*U
    P3 = 0.15*h*U+0.2*h*W
    P1 = P0+ 0.5*(P3-P0)
    P2 = P0+ 0.5*(P3-P0)
    
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

    #cuerdas
    P0= P3                  #borde de la cesta
    P1= O+h*W+0.4*h*U       #borde del globo

    radioCesta=0.16*h
    radioGlobo=0.42*h
    ang= 2*pi/nCuerdas
    i=0
    while i<nCuerdas:
        P0= O + radioCesta*cos(i*ang)*U + radioCesta*sin(i*ang)*V + 0.2*h*W
        P1= O + radioGlobo*cos(i*ang)*U + radioGlobo*sin(i*ang)*V + h*W
        curve(pos=[P0,P1], color= col2)
        i= i+1
    faces(pos = colocar(lista1,O,U,V,W,1,1,1), normal=colocar(lista2,O,U,V,W,1,1,1), color=col3)    #cesta
    sphere(pos=O+h*W, radius= 0.4*h, color= col1)                                                   #globo
    ring(pos=O+h*W, axis= W, radius= 0.4*h, color= col2)                                            #anilloGlobo
    cylinder(pos=O,radius=0.1*h,axis=0.1*W,color=col3)                                              #sueloCesta
    ring(pos=O+0.2*h*W, axis=W, radius=0.15*h, color= col2)                                         #anilloCesta
    
    



#P0=(-20,0,-20)
#P1=(-20,0,20)
#P2=(20,0,20)
#P3=(20,0.1,-20)
#Q0=(-20,-2,-20)
#Q1=(-20,-2,20)
#Q2=(20,-2,20)
#Q3=(20,-2,-20)
#convex(pos=[P0,P1,P2,P3,Q0,Q1,Q2,Q3],color=color.green)

#globo(10,10,vector(0,0,0),vector(1,0,0),vector(0,1,0),vector(0,0,1),color.yellow, color.orange, color.blue)

