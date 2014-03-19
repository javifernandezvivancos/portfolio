from visual import *
from lector import *


def modulo_banco(c,u,v,w,a,l,h,pico,col):
    listav=[]
    listac=[]

    p0= c + ((a-pico)*1./2)*u + ((l-pico)*1./2)*v
    p1= c + ((a-pico)*1./2)*u - ((l-pico)*1./2)*v
    p2= c - ((a-pico)*1./2)*u - ((l-pico)*1./2)*v
    p3= c - ((a-pico)*1./2)*u + ((l-pico)*1./2)*v

    p4= c + (a*1./2)*u + (l*1./2)*v  + pico*w
    p5= c + (a*1./2)*u - (l*1./2)*v  + pico*w
    p6= c - (a*1./2)*u - (l*1./2)*v  + pico*w
    p7= c - (a*1./2)*u + (l*1./2)*v  + pico*w

    p8= p4 + (h-pico*2)*w
    p9= p5 + (h-pico*2)*w
    p10= p6 + (h-pico*2)*w
    p11= p7 +(h-pico*2)*w

    p12= p0 + h*w
    p13= p1 + h*w
    p14= p2 + h*w
    p15= p3 + h*w

    listav+=[p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15]
    cara0=[0,3,2,1]
    cara1=[0,4,7,3]
    cara2=[3,7,6,2]
    cara3=[2,6,5,1]
    cara4=[1,5,4,0]
    cara5=[5,9,8,4]
    cara6=[4,8,11,7]
    cara7=[7,11,10,6]
    cara8=[6,10,9,5]
    cara9=[8,9,13,12]
    cara10=[8,12,15,11]
    cara11=[11,15,14,10]
    cara12=[10,14,13,9]
    cara13=[12,13,14,15]
    
    listac+=[cara0,cara1,cara2,cara3,cara4,cara5,cara6,cara7,cara8,cara9,cara10,cara11,cara12,cara13]
    dibujar(listav,listac,pon_vectores_c(listav,listac),col,2,1,0)

def banco(c,u,v,w,a,l,h,h2,g,pico,col):
    #Patas
    cpatader=c + (((a*1.)/2) - ((g*1.)/2))*-u
    cpataizq=c + (((a*1.)/2) - ((g*1.)/2))*u
    modulo_banco(cpatader,u,v,w,g,l,h,pico,col)
    modulo_banco(cpataizq,u,v,w,g,l,h,pico,col)
    #Asiento
    modulo_banco(c+h2*w*.75,u,v,w,a-g,l,g,pico,col)
    #Respaldo
    modulo_banco(c+h2*w,u,v,w,a-g,g,l*1./2,pico,col)
    
#banco(vector(0,0,0),vector(1,0,0),vector(0,0,1),vector(0,1,0),10,5,4,1.75,1,.2,color.white)
