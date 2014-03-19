# -*- coding: cp1252 -*-
from visual import *


# tipo indica como vamos a colorear
#   tipo=0 es colorear por vértices: listac debe tener la misma longitud que listav
#   tipo=1 es colorear por caras: listac debe tener la misma longitud que listac
#   tipo=2 es colorear todo el objeto: listac es un color
#tipo 2 indica el modo de iluminación
#   tipo2=0 es iluminar por vértices: listan debe tener la misma longitud que listav
#   tipo2=1 es iluminar por caras: listan debe tener la misma longitud que listac
#doble indica si la cara es doble o no
#   doble=0 indica ue no es doble
#   doble=1 es doble

def dibujar(listav,listac,listan,listacol,tipo,tipo2,doble):
    ob=faces()
    lis1=[]
    lis2=[]
    lis3=[]
    i=0
    for H in listac:
        if len(H)==3:
            lis1+=[listav[H[0]],listav[H[1]],listav[H[2]]]
            if tipo2==0:
                lis2+=[listan[H[0]],listan[H[1]],listan[H[2]]]
            else:
                lis2+=[listan[i],listan[i],listan[i]]
            if tipo==0:
                lis3+=[listacol[H[0]],listacol[H[1]],listacol[H[2]]]
            if tipo==1:
                lis3+=[listacol[i],listacol[i],listacol[i]]
        else:
            lis1+=[listav[H[0]],listav[H[1]],listav[H[2]]]
            lis1+=[listav[H[0]],listav[H[2]],listav[H[3]]]
            if tipo2==0:
                lis2+=[listan[H[0]],listan[H[1]],listan[H[2]]]
                lis2+=[listan[H[0]],listan[H[2]],listan[H[3]]]
            else:
                lis2+=[listan[i],listan[i],listan[i]]
                lis2+=[listan[i],listan[i],listan[i]]
            if tipo==0:
                lis3+=[listacol[H[0]],listacol[H[1]],listacol[H[2]]]
                lis3+=[listacol[H[0]],listacol[H[2]],listacol[H[3]]]
            if tipo==1:
                lis3+=[listacol[i],listacol[i],listacol[i]]
                lis3+=[listacol[i],listacol[i],listacol[i]]
        i+=1

    if tipo==0:
        ob.color=lis3
    if tipo==1:
        ob.color=lis3
    if tipo==2:
        ob.color=listacol
    if doble==1:
        h=len(lis1)
        i=0
        while i<h:
            lis1+=[lis1[i],lis1[i+2],lis1[i+1]]
            lis2+=[lis2[i],lis2[i+2],lis2[i+1]]
            if tipo<=1:
                lis3+=[lis3[i],lis3[i+2],lis3[i+1]]
            i+=3
    ob.pos=lis1
    ob.normal=lis2            
    return ob


def pon_vectores_c(listav,listac):
    listan=[]
    for H in listac:
        v=cross(listav[H[1]]-listav[H[0]],listav[H[2]]-listav[H[1]])
        if mag(v)>0:
            v=norm(v)
        listan+=[v]
    return listan




