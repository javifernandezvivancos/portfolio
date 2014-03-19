from visual import*
from lector2 import*
from matrices import*
from ventanaRedonda1 import*
from ventana1 import*
from puerta1 import*
from valla1 import*

def tejado(P4,P5,P6,P7,P8,P9,h1,u,v,w,colorVigas):
    #Tejado parte blanca
    saliente=h1/13
    
    salienteFron=v*saliente
    P8=P8+salienteFron    
    P4=P4+salienteFron
    P7=P7+salienteFron
    P10=P8+w*saliente #vector(0,saliente,0)
    P11=P9+w*saliente #vector(0,saliente,0)
    P12=P4+u*saliente #vector(saliente,0,0)
    P13=P5+u*saliente #vector(saliente,0,0)
    P14=P6+u*-saliente#vector(-saliente,0,0)
    P15=P7+u*-saliente#vector(-saliente,0,0)
    listav=[P4,P12,P13,P5,P8,P10,P11,P9,P7,P6,P14,P15]

    c0=[0,4,7,3]
    c1=[4,8,9,7]
    c2=[0,1,5,4]
    c3=[4,5,11,8]
    c4=[0,3,2,1]
    c5=[9,8,11,10]
    c6=[6,10,11,5]
    c7=[1,2,6,5]
    c8=[6,7,9,10]
    c9=[7,6,2,3]
    listac=[c0,c1,c2,c3,c4,c5,c6,c7,c8,c9]
    
    dibujar(listav,listac,pon_vectores_c(listav,listac),colorVigas,2,1,1)

    #Tejado parte roja
    saliente = .5*saliente
    
    P4=P12
    P5=P13
    P6=P14
    P7=P15
    P8=P10
    P9=P11
    P10=P8+w*saliente #vector(0,saliente,0)
    P11=P9+w*saliente #vector(0,saliente,0)
    P12=P4+u*saliente #vector(saliente,0,0)
    P13=P5+u*saliente #vector(saliente,0,0)
    P14=P6+u*-saliente#vector(-saliente,0,0)
    P15=P7+u*-saliente#vector(-saliente,0,0)

    listav=[P4,P12,P13,P5,P8,P10,P11,P9,P7,P6,P14,P15]

    c0=[0,4,7,3]
    c1=[4,8,9,7]
    c2=[0,1,5,4]
    c3=[4,5,11,8]
    c4=[0,3,2,1]
    c5=[9,8,11,10]
    c6=[6,10,11,5]
    c7=[1,2,6,5]
    c8=[6,7,9,10]
    c9=[7,6,2,3]
    listac=[c0,c1,c2,c3,c4,c5,c6,c7,c8,c9]
    
    dibujar(listav,listac,pon_vectores_c(listav,listac),color.red,2,1,1)

def ventanas(anchura,profundidad,h1,h2,O,u,v,w,colorVentanas,colorVigas,p7):
    i=0.076923*h1 #Grosor de las vigas
    
    #Ventana redonda frontal superior
    posicion = p7+i*2*w+0.5*anchura*u
    cylinder(pos=posicion,radius=i*1.5,axis=0.05*i*v,color=colorVentanas)
    ventanaRedonda(posicion,i,v,w,colorVigas)

    #Ventanas cuadradas frontales
        #superior derecha
    posicion = p7-i*4*w+i*4*u
    ventana(posicion,u,v,w,3*i,2*i,0.5*i,colorVentanas,colorVigas,1,1,1)
        #superior izquierda
    posicion = posicion + 0.5*anchura*u
    ventana(posicion,u,v,w,3*i,2*i,0.5*i,colorVentanas,colorVigas,1,1,1)
        #inferior izquierda
    posicion = posicion-6*i*w
    ventana(posicion,u,v,w,3*i,2*i,0.5*i,colorVentanas,colorVigas,1,0,1)
        #inferior derecha
    posicion = posicion- 0.5*anchura*u
    ventana(posicion,u,v,w,3*i,2*i,0.5*i,colorVentanas,colorVigas,1,0,1)

    #Puerta frontal inferior
    posicion=p7-i*10.75*w+0.5*anchura*u    
        #Escalon de la puerta inferior
    box(pos=posicion-2.125*i*w+0.5*i*v,size=(2*i,0.25*i,i))
    puerta(posicion,u,v,w,2*i,4*i,0.5*i,colorVentanas,colorVigas)
    #Puerta frontal superior
    posicion=posicion+5.7*i*w
    puerta(posicion,u,v,w,2*i,4*i,0.5*i,colorVentanas,colorVigas)


    #Ventanas cuadradas L.I:
        #central superior
    posicion=p7-0.5*profundidad*v-4*i*w
    ventana(posicion,v,-u,w,3*i,2*i,0.5*i,colorVentanas,colorVigas,0,0,1)
        #izquierda superior
    posicion=posicion-.30*profundidad*v
    ventana(posicion,v,-u,w,3*i,2*i,0.5*i,colorVentanas,colorVigas,0,1,1)
        #izquierda inferior
    ventana(posicion-6*i*w,v,-u,w,3*i,2*i,0.5*i,colorVentanas,colorVigas,0,0,0)
        #derecha superior
    posicion=posicion+.60*profundidad*v
    ventana(posicion,v,-u,w,3*i,2*i,0.5*i,colorVentanas,colorVigas,0,1,1)

    #Ventanas cuadradas L.D:
        #izquierda superior
    posicion=posicion+anchura*u
    ventana(posicion,-v,u,w,3*i,2*i,0.5*i,colorVentanas,colorVigas,0,1,1)
        #central superior
    posicion=posicion-.30*profundidad*v
    ventana(posicion,-v,u,w,3*i,2*i,0.5*i,colorVentanas,colorVigas,0,0,1)
        #derecha superior
    posicion=posicion-.30*profundidad*v
    ventana(posicion,-v,u,w,3*i,2*i,0.5*i,colorVentanas,colorVigas,0,0,1)
        #derecha inferior
    ventana(posicion-6*i*w,-v,u,w,3*i,2*i,0.5*i,colorVentanas,colorVigas,0,0,0)
    
def detallesMuros(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,h1,h2,anchura,profundidad,O,u,v,w,colorVigas):
    i=0.076923*h1 #Grosor de la viga
    
    #Vigas verticales
    p10=p7+i*u+i*w+0.0001*v #p10 = vector(p7[0]+i,p7[1]+i,p7[2]+0.0001)
    p11=p4-i*u+i*w+0.0001*v #p11 = vector(p4[0]-i,p4[1]+i,p4[2]+0.0001)    
    p12=p3+i*u+0.0001*v #vector(p3[0]+i,p3[1],p3[2]+0.0001)
    p13=p0-i*u+0.0001*v #vector(p0[0]-i,p0[1],p0[2]+0.0001)
    p14=p7-0.0001*u-i*v #vector(p7[0]-0.0001,p7[1],p7[2]-i)
    p15=p3-0.0001*u-i*v #vector(p3[0]-0.0001,p3[1],p3[2]-i)
    p16=p4+0.0001*u-i*v #vector(p4[0]+0.0001,p4[1],p4[2]-i)
    p17=p0+0.0001*u-i*v #vector(p0[0]+0.0001,p0[1],p0[2]-i)
    p20=p10-(profundidad-0.0002)*v #vector(p10[0],p10[1],p10[2]-profundidad-0.0002)
    p21=p11-(profundidad-0.0002)*v #vector(p11[0],p11[1],p11[2]-profundidad-0.0002)
    p22=p12-(profundidad-0.0002)*v #vector(p12[0],p12[1],p12[2]-profundidad-0.0002)
    p23=p13-(profundidad-0.0002)*v #vector(p13[0],p13[1],p13[2]-profundidad-0.0002)
    p24=p14-(profundidad-2*i)*v #vector(p14[0],p14[1],p14[2]-profundidad+2*i)
    p25=p15-(profundidad-2*i)*v #vector(p15[0],p15[1],p15[2]-profundidad+2*i)
    p26=p16-(profundidad-2*i)*v #vector(p16[0],p16[1],p16[2]-profundidad+2*i) 
    p27=p17-(profundidad-2*i)*v #vector(p17[0],p17[1],p17[2]-profundidad+2*i)
    listav=[p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p20,p21,p22,p23,p24,p25,p26,p27]
    
    c0=[12,10,7,3]
    c1=[4,11,13,0]
    c2=[7,14,15,3]
    c3=[4,0,17,16]
    c4=[18,20,2,6]
    c5=[19,5,1,21]
    c6=[22,6,2,23]
    c7=[1,5,24,25]
    listac=[c0,c1,c2,c3,c4,c5,c6,c7]

    dibujar(listav,listac,pon_vectores_c(listav,listac),colorVigas,2,1,1)

    #Vigas horizontales
    box(pos=O+5.5*i*w,size=(i,anchura+0.001,profundidad+0.001),axis=w,color=colorVigas)
    box(pos=O+11.5*i*w,size=(i,anchura+0.001,profundidad+0.001),axis=w,color=colorVigas)

    #lineas horizontales
    pi1=p13
    pi2=p23
    pi3=p22
    pi4=p12
    pi5=p15
    pi6=p25
    pi7=p17
    pi8=p27
    j=i
    while(j<=h1):
        pi1 = pi1+i*w+0.001*v
        pi2 = pi2+i*w-0.001*v
        pi3 = pi3+i*w-0.001*v
        pi4 = pi4+i*w+0.001*v
        pi5 = pi5+i*w+0.001*v
        pi6 = pi6+i*w+0.001*v
        pi7 = pi7+i*w+0.001*v
        pi8 = pi8+i*w+0.001*v
        curve(pos=[pi4,pi1],color=(0.75,0.75,0.75))
        curve(pos=[pi2,pi3],color=(0.75,0.75,0.75))
        curve(pos=[pi5,pi6],color=(0.75,0.75,0.75))
        curve(pos=[pi7,pi8],color=(0.75,0.75,0.75))
        j = j+i
    pi1=p7
    pi2=p4
    pi3=p6
    pi4=p5
    while(j<h2):
        pi1=pi1+(0.2*0.5*anchura*u+i*w+0.001*v)
        pi2=pi2+(-0.2*0.5*anchura*u+i*w+0.001*v)
        pi3=pi3+(0.2*0.5*anchura*u+i*w-0.001*v)
        pi4=pi4+(-0.2*0.5*anchura*u+i*w-0.001*v)
        curve(pos=[pi1,pi2],color=(0.75,0.75,0.75))
        curve(pos=[pi3,pi4],color=(0.75,0.75,0.75))
        j = j+i

    #Terraza
    longTerraza=0.33*profundidad
    box(pos=p7+.5*anchura*u-7.5*i*w+0.5*longTerraza*v,size=(i,anchura,longTerraza),axis=w,color=colorVigas)
    #Valla de la terraza
    vallaInterior(p7,p7-7*i*w,p4-7*i*w,p4,p7+longTerraza*v-i*w,p7+longTerraza*v-7*i*w,p4+longTerraza*v-7*i*w,p4+longTerraza*v-i*w,0.1*i,color.orange)
    #Vigas redondas para sujetarla
    pv0=p3+i*u+(longTerraza-i)*v
    pv1=pv0+5*i*w
    cylinder(pos=pv0,axis=pv1-pv0,radius=.5*i,color=colorVigas)
    pv0=p0-i*u+(longTerraza-i)*v
    pv1=pv0+5*i*w
    cylinder(pos=pv0,axis=pv1-pv0,radius=.5*i,color=colorVigas)
    
def casa(anchura,profundidad,h1,h2,O,u,v,w,colorCasa,colorVigas,colorVentanas):
    #Estructura de la casa
    P0=O+.5*anchura*u+.5*profundidad*v
    P1=P0-profundidad*v
    P2=P1-anchura*u
    P3=P2+profundidad*v    
    P4=P0+h1*w
    P5=P1+h1*w
    P6=P2+h1*w
    P7=P3+h1*w    
    P8=O+.5*profundidad*v+h2*w
    P9=P8-profundidad*v    
    listav=[P0,P1,P2,P3,P4,P5,P6,P7,P8,P9]
    
    c0=[0,3,2,1]
    c1=[0,1,5,4]
    c2=[1,2,6,5]
    c3=[2,3,7,6]
    c4=[3,0,4,7]
    c6=[4,8,7]
    c7=[6,9,5]
    listac=[c0,c1,c2,c3,c4,c6,c7]

    dibujar(listav,listac,pon_vectores_c(listav,listac),colorCasa,2,1,1)
    
    #Tejado de la casa
    tejado(P4,P5,P6,P7,P8,P9,h1,u,v,w,colorVigas)
    
    #Adornos de las paredes y terraza
    detallesMuros(P0,P1,P2,P3,P4,P5,P6,P7,P8,P9,h1,h2,anchura,profundidad,O,u,v,w,colorVigas)

    #Ventanas y puertas
    ventanas(anchura,profundidad,h1,h2,O,u,v,w,colorVentanas,colorVigas,P7)

    #Jardin
    #box(pos=O+0.25*profundidad*v,size=(0.05,anchura,1.5*profundidad),color=color.green,axis=w) #Cesped
    box(pos=O+0.65*profundidad*v,size=(0.025*h1,2*0.076923*h1,2*0.076923*h1),color=colorVigas,axis=w) #Losa
    #box(pos=O+0.80*profundidad*v,size=(0.025*h1,2*0.076923*h1,2*0.076923*h1),color=colorVigas,axis=w) #losa
    #box(pos=O+0.95*profundidad*v,size=(0.025*h1,2*0.076923*h1,2*0.076923*h1),color=colorVigas,axis=w) #losa
    
#casa(120,150,100,130,vector(0,0,0),vector(1,0,0),vector(0,0,1),vector(0,1,0),color.yellow,color.white,color.blue)
