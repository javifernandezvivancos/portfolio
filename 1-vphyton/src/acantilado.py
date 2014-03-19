from visual import *
from lector import *
from fractales import *

def pon_acantilado(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15):
    malla1=[[p0,p1,p2,p3],[p4,p5,p6,p7]]
    malla2=[[p4,p5],[p8,p9]]
    malla3=[[p9,p5],[p14,p12]]
    malla4=[[p6,p7],[p13,p15]]
    malla5=[[p13,p15],[p12,p14]]

    h=20.
    d=2.
    suav=3
    i=0
    while i<5:
        malla1= iterar(malla1,d,h)
        malla2= iterar(malla2,d,h)
        malla3= iterar(malla3,d,h)
        malla4= iterar(malla4,d,h)
        malla5= iterar(malla5,d,h)
        h= h/suav
        d= d/suav
        i+=1
    lista1= ponCaras(malla1)
    lista2= ponCaras(malla2)
    lista3= ponCaras(malla3)
    lista4= ponCaras(malla4)
    lista5= ponCaras(malla5)

    convex(pos=[p5,p12,p13,p6],color=(.7,.5,0)) #suelo de la casa
    dibujar(lista1[0],lista1[1],pon_vectores_c(lista1[0],lista1[1]),(.7,.5,0),2,1,0)
    dibujar(lista2[0],lista2[1],pon_vectores_c(lista2[0],lista2[1]),(.7,.5,0),2,1,0)
    dibujar(lista3[0],lista3[1],pon_vectores_c(lista3[0],lista3[1]),(.7,.5,0),2,1,0)
    dibujar(lista4[0],lista4[1],pon_vectores_c(lista4[0],lista4[1]),(.7,.5,0),2,1,0)
    dibujar(lista5[0],lista5[1],pon_vectores_c(lista5[0],lista5[1]),(.7,.5,0),2,1,0)
