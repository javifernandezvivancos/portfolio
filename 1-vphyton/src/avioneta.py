from visual import *
from bezier import *
from subrutinas import *

def avioneta(radio,O,ejex,ejey,ejez,col1,col2,col3,col4):
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

    #cuerpo de la avioneta, por revolucion
    P0 = vector(radio,0,0)
    P1 = vector(1*radio,2*radio,0)
    P2 = vector(0.1*radio,4*radio,0)
    P3 = vector(0.3*radio,6*radio,0)    
##    sphere(pos=P0)
##    sphere(pos=P1,color=color.yellow)
##    sphere(pos=P2,color=color.yellow)
##    sphere(pos=P3)
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
    faces(pos = colocar(lista1,O,ejey,ejez,ejex,1,1,1), normal=colocar(lista2,O,ejex,ejez,ejey,1,1,1), color=col1)   
    #tapas del cuerpo
    cylinder(pos=O,axis=0.3*ejex,radius=radio,color=col1)
    cylinder(pos=O+radio*5.7*ejex,axis=0.3*ejex,radius=0.3*radio,color=col1)
    #helice
    cone(pos=O,axis=radio*-ejex,radius=.4*radio,color=col2)
    box(pos=O-0.3*radio*ejex,size=(0.1*radio,0.3*radio,2.5*radio),color=col2)
    box(pos=O-0.3*radio*ejex,size=(0.1*radio,2.5*radio,0.3*radio),color=col2)
    #alas
    box(pos=O+1.5*radio*ejex,size=(1.5*radio,.2*radio,7*radio),color=col3)
    #estabilizador trasero
    box(pos=O+5.4*radio*ejex,size=(.5*radio,.1*radio,radio),color=col3)
    box(pos=O+5.4*radio*ejex+.2*radio*ejey,size=(.5*radio,.8*radio,.1*radio),color=col3)
    #tren de aterrizaje
    cylinder(pos=O+1.5*radio*ejex,axis=radio*ejez-radio*ejey,color=col3,radius=.05*radio)
    cylinder(pos=O+1.5*radio*ejex,axis=-radio*ejez-radio*ejey,color=col3,radius=.05*radio)
    posR1=O+1.5*radio*ejex+radio*ejez-radio*ejey
    posR2=O+1.5*radio*ejex-radio*ejez-radio*ejey
    sphere(pos=posR1,radius=.05*radio,color=col3)
    sphere(pos=posR2,radius=.05*radio,color=col3)
    cylinder(pos=posR1,axis=-radio*ejez,radius=.2*radio,color=color.black)
    cylinder(pos=posR2,axis=radio*ejez,radius=.2*radio,color=color.black)
    #pancarta de publicidad
    box(pos=O+12*radio*ejex,size=(10*radio,2*radio,0.02*radio),color=col4)
    p0=O+5.7*radio*ejex+0.3*radio*ejey
    p1=p0+1.3*radio*ejex+.6*radio*ejey
    curve(pos=[p0,p1])
    p0=O+5.7*radio*ejex-0.3*radio*ejey
    p1=p0+1.3*radio*ejex-.6*radio*ejey
    curve(pos=[p0,p1])
##O=vector(0,0,0)
##ejex=vector(1,0,0)
##ejey=vector(0,1,0)
##ejez=vector(0,0,1)
##avioneta(50,O,ejex,ejey,ejez,color.green,color.yellow,color.yellow,color.white)
