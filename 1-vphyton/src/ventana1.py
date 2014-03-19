from visual import*

def ventana(O,u,v,w,anchura,altura,profundidad,color1,color2,pintura,rejillas,repisa):
#O es el centro de la ventana.
#pintura vale 0 o 1, 1 si queremos que tenga una capa de pintura triangular superior y 0 si no
#rejillas vale 0 o 1, 1 si queremos que tenga rejillas y 0 si no
#repisa vale 0 o 1, 1 si queremos que tenga una repisa del color2 y 0 si no.

    #pintura triangular superior
    if(pintura==1):
        p0=O+.7*altura*w+0.005*v
        p1=O-.5*anchura*u+.5*altura*w+0.005*v
        p2=O+.5*anchura*u+.5*altura*w+0.005*v
        convex(pos=[p0,p1,p2],color=color1)

    #Ventana basica
    O=O+0.5*profundidad*v
    box(pos=O,size=(anchura,altura,profundidad),axis=u,color=color1)
    O=O-u*anchura*0.214285
    box(pos=O,size=(0.285714*anchura,0.6*altura,0.002+profundidad),axis=u,color=color.black)
    O=O+2*u*anchura*0.214285
    box(pos=O,size=(0.285714*anchura,0.6*altura,0.002+profundidad),axis=u,color=color.black)
    O=O-u*anchura*0.214285

    #Rejillas
    if(rejillas==1):
        numTiras=10
        distancia=0.6*altura/numTiras
        i=0.3*altura
        O=O+0.5*profundidad*v
        while(i>-0.3*altura):
            p0=O+(i-distancia)*w-0.071428*anchura*u+distancia*v
            p1=p0+distancia*w-distancia*v
            p2=p1-0.285714*anchura*u
            p3=p2-distancia*w+distancia*v
            convex(pos=[p0,p1,p2,p3],color=color1)
    
            p0=O+(i-distancia)*w+0.071428*anchura*u+distancia*v
            p1=p0+distancia*w-distancia*v
            p2=p1+0.285714*anchura*u
            p3=p2-distancia*w+distancia*v
            convex(pos=[p0,p1,p2,p3],color=color1)
        
            i=i-distancia
    #repisa
    if(repisa==1):
        box(pos=O-0.05*altura*w-0.5*altura*w,size=(anchura,0.1*altura,2*profundidad),axis=u,color=color2)


