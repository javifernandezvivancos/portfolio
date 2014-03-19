from visual import*
from CRom import*
def subeBaja(O,u,v,w,escala,col1,col2,col3):
    #soportes
    distancia=8
    P0 = O +(20*u-20*w-.5*distancia*v)*escala
    P1 = O -(10*u+.5*distancia*v)*escala
    P2 = O +(15*w-5*u-.5*distancia*v)*escala
    P3 = O +(20*w-.5*distancia*v)*escala
    P4 = O +(5*u+15*w-.5*distancia*v)*escala
    P5 = O +(10*u-.5*distancia*v)*escala
    P6 = O -(20*u+20*w+.5*distancia*v)*escala
    listap = [P0,P1,P2,P3,P4,P5,P6]
    P00=P0+distancia*escala*v
    P11=P1+distancia*escala*v
    P22=P2+distancia*escala*v
    P33=P3+distancia*escala*v
    P44=P4+distancia*escala*v
    P55=P5+distancia*escala*v
    P66=P6+distancia*escala*v
    listap2 = [P00,P11,P22,P33,P44,P55,P66]

    npuntos=100
    inct=1./npuntos
    lista=[]
    lista2=[]
    t=0
    while t<1+inct:
        if t>1:
            t=1
        qB=CRom(listap,t)
        qB2=CRom(listap2,t)
        lista+=[qB]
        lista2+=[qB2]
        t+=inct
    curve(pos=lista,radius=escala,color=col1)
    curve(pos=lista2,radius=escala,color=col1)
    convex(pos=lista,color=col1)
    convex(pos=lista2,color=col1)
    
    #barra de equilibrio
    sphere(pos=P33-10*w*escala,radius=2*escala,color=col2)
    sphere(pos=P3-10*w*escala,radius=2*escala,color=col2)
    cylinder(pos=P3-10*w*escala,axis=distancia*v*escala,radius=2*escala,color=col2)
    #palo largo
    ang=.05*pi
    ug=norm(cos(ang)*u+sin(ang)*w)
    box(pos=O+10*w*escala,size=(100*escala,3*escala,4*escala),axis=ug,color=col2)
    #asientos
    Pasiento=O+(ug*47+12*w)*escala
    box(pos=Pasiento,size=(5*escala,1*escala,7*escala),axis=ug,color=col3)
    Ppalo= O+(ug*43+16*w-4*v)*escala
    cylinder(pos=Ppalo,axis=8*escala*v,radius=.5*escala,color=col3)
    Ppalo= O+(ug*43.7+11*w)*escala
    wg=cross(v,ug)
    cylinder(pos=Ppalo,axis=wg*5*escala,radius=.5*escala,color=col3)
    
    Pasiento=O+(-ug*48+12*w)*escala    
    box(pos=Pasiento,size=(5*escala,1*escala,7*escala),axis=ug,color=col3)
    Ppalo= O+(-ug*45+16*w-4*v)*escala
    cylinder(pos=Ppalo,axis=8*escala*v,radius=.5*escala,color=col3)
    Ppalo= O+(-ug*44.2+11*w)*escala
    wg=cross(v,ug)
    cylinder(pos=Ppalo,axis=wg*5*escala,radius=.5*escala,color=col3)

#subeBaja(vector(0,0,0),vector(1,0,0),vector(0,0,1),vector(0,1,0),1,color.orange,color.yellow,color.orange)

