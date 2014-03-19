from visual import*
    
def chiringuito(anchura,profundidad,h1,O,u,v,w,col):
    #Puntos
    P0=O+.5*anchura*u+.5*profundidad*v
    P1=P0-profundidad*v
    P2=P1-anchura*u    
    P3=P2+profundidad*v
    P4=P0+h1*w
    P5=P1+h1*w
    P6=P2+h1*w
    P7=P3+h1*w
    distanciaPalos= 1
    grosorPalos= .5
    nPalosAnch= mag(P1-P2)
    nPalosProf= mag(P0-P1)
    #pared anterior
    i=0
    Paux2=P2
    Paux3=P2
    Paux4=P1
    Q=h1*w
    while(i<=nPalosAnch):
        cylinder(pos=Paux2,axis=Q,color=col,radius=grosorPalos)
        Paux2=Paux2+u*distanciaPalos
        i=i+distanciaPalos
    i=0
    #paredes laterales
    while(i<nPalosProf):
        cylinder(pos=Paux3,axis=Q,color=col,radius=grosorPalos)
        cylinder(pos=Paux4,axis=Q,color=col,radius=grosorPalos)
        Paux3=Paux3+v*distanciaPalos
        Paux4=Paux4+v*distanciaPalos
        i=i+distanciaPalos
    #techo
    i=0
    Paux=P6-grosorPalos*v
    Q=1.35*profundidad*v
    while(i<=nPalosAnch):
        cylinder(pos=Paux,axis=Q,color=col,radius=grosorPalos)
        Paux=Paux+u*distanciaPalos
        i=i+distanciaPalos
    #frontal
    i=0
    Paux=P3
    Q=h1*w
    while(i<.1*nPalosAnch):
        cylinder(pos=Paux,axis=Q,color=col,radius=grosorPalos)
        Paux=Paux+u*distanciaPalos
        i=i+distanciaPalos
    Q=.5*h1*w
    while(i<.9*nPalosAnch):
        cylinder(pos=Paux,axis=Q,color=col,radius=grosorPalos)
        Paux=Paux+u*distanciaPalos
        i=i+distanciaPalos
    Q=h1*w
    while(i<=nPalosAnch):
        cylinder(pos=Paux,axis=Q,color=col,radius=grosorPalos)
        Paux=Paux+u*distanciaPalos
        i=i+distanciaPalos
    #barra
    box(pos=O+.7*profundidad*v+.5*h1*w, size=(.8*anchura,1,.5*profundidad),color=col)
    
#chiringuito(30,20,20,vector(0,0,0),vector(1,0,0),vector(0,0,1),vector(0,1,0),color.orange)
