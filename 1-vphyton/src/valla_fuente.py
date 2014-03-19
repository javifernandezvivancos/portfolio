from visual import *
from curvas import *

def valla(p,q,nobjetos,h,h2,h3,g,col):
    inc= 1./(nobjetos-1)*(q-p)
    i=0
    listaborde=[]
    #Posters
    while i<nobjetos: 
        p0=p+inc*i
        p1=p0+vector(0,h,0)
        curve(pos=[p0,p1],color=col,radius=g)
        listaborde+=[p0]
        i+=1
    i=0
    curve(pos=listaborde,color=color.red,radius=g)
    #Arco Superior
    while i<nobjetos-1:        
        q0=p+i*inc+vector(0,h,0)
        q3=q0+inc
        q1=q0+.3*inc+vector(0,h2,0)
        q2=q1+.4*inc
        npuntos=100
        inct=1./npuntos
        lista=[]
        t=0
        while t<1+inct:
            if t>1:
                t=1
            qB=Bez(q0,q1,q2,q3,t)
            lista+=[qB]
            t+=inct
        curve(pos=lista,color=col,radius=g)
        i+=1
    i=0
    #Arco Medio
    while i<nobjetos-1:        
        q0=p+i*inc+vector(0,h3,0)
        q3=q0+inc
        q1=q0+.3*inc+vector(0,h3,0)
        q2=q1+.4*inc
        npuntos=100
        inct=1./npuntos
        lista=[]
        t=0
        while t<1+inct:
            if t>1:
                t=1
            qB=Bez(q0,q1,q2,q3,t)
            lista+=[qB]
            t+=inct
        curve(pos=lista,color=col,radius=g)
        i+=1
        
def poligonoconvallas(p,r,aini,nlados,nobjetos,h,h2,h3,g,col):
    ang=2*pi/nlados
    lista=[]
    listasuelo=[]
    i=0
    while i<nlados:
        v0=p+r*vector(cos(i*ang+aini),0,sin(i*ang+aini))
        lista+=[v0]
        listasuelo+=[v0+vector(0,0.001,0)]
        v1=p+r*vector(cos((i+1)*ang+aini),0,sin((i+1)*ang+aini))
        valla(v0,v1,nobjetos,h,h2,h3,g,col)
        i+=1
    convex(pos=listasuelo,color=col)

#poligonoconvallas(vector(0,0,0),20,pi/8,8,10,5,2,2,.2,color.green)
