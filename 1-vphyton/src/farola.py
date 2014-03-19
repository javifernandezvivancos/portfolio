from visual import *
from lector import *

def farola(c,u,v,w,h,h2,h3,g,col,col1):
    listav=[]
    listac=[]
    listavcristal=[]
    listaccristal=[]
    angini=pi/4
    angg=2*pi/4
    i=0
    while i<4:
        #p= c + (g/2.5)*vector(cos(angini+angg*i),0,sin(angini+angg*i))
        p=c+(g/2.5)*u*cos(angini+angg*i) + (g/2.5)*v*sin(angini+angg*i)
        listav+=[p]
        i+=1
    i=0
    while i<4:
        #p=c+(g/2.5)*vector(cos(angini+angg*i),h3/(g/2),sin(angini+angg*i))
        p=c+(g/2.5)*u*cos(angini+angg*i) + (g/2.5)*v*sin(angini+angg*i) + h3*w
        listav+=[p]
        i+=1
    i=0
    while i<4:
        #p=c+(g/4.)*vector(cos(angini+angg*i),(h3+h3/4.)/(g/4.),sin(angini+angg*i))
        p=c+(g/4.)*u*cos(angini+angg*i) + (g/4.)*v*sin(angini+angg*i) + h3*2*w
        listav+=[p]
        i+=1
    i=0
    while i<4:
       # p=c+(g/4.)*vector(cos(angini+angg*i),(h2+h3-g/4.)/(g/4.),sin(angini+angg*i))
        p=c+(g/4.)*u*cos(angini+angg*i) + (g/4.)*v*sin(angini+angg*i) + (h2+h3-g/4.)*w
        listav+=[p]
        i+=1
    i=0
    ugaux=u
    vgaux=v
    while i<4:
        ugaux=cos(pi/2*i)*u+sin(pi/2*i)*v
        vgaux=cross(ugaux,w)
        #p=c+(g-(g/4.))*vector(cos(angini+angg*i),(h2+h3)/(g-(g/4.)),sin(angini+angg*i))
        p=c+(g-(g/4.))*u*cos(angini+angg*i) + (g-(g/4.))*v*sin(angini+angg*i) + (h2+h3)*w
        r=p-(g/10.)*vgaux
        q=p-(g/10.)*ugaux
        listav+=[p]
        listavcristal+=[r,p,q]
        i+=1
    i=0
    ugaux=u
    vgaux=v
    while i<4:
        ugaux=cos(pi/2*i)*u+sin(pi/2*i)*v
        vgaux=cross(ugaux,w)
        #p=c+g*vector(cos(angini+angg*i),(h-g/4.)/g,sin(angini+angg*i))
        p=c+g*u*cos(angini+angg*i) + g*v*sin(angini+angg*i) + (h-g/4.)*w
        r=p-(g/10.)*vgaux
        q=p-(g/10.)*ugaux
        listav+=[p]
        listavcristal+=[r,p,q]
        i+=1
    i=0
    while i<4:
        #p=c+(g-(g/4.))*vector(cos(angini+angg*i),h/(g-(g/4.)),sin(angini+angg*i))
        p=c+(g-(g/4.))*u*cos(angini+angg*i) + (g-(g/4.))*v*sin(angini+angg*i) + h*w
        listav+=[p]
        i+=1
    i=0
    while i<4:
        curvacristal=curve(color=col,radius=0.01)
        i1=i
        i2=(i1+1)%4
        n=4
        m=12
        cara1=[i1,i1+n,i2+n,i2]
        cara2=[i1+n,i1+n*2,i2+n*2,i2+n]
        cara3=[i1+n*2,i1+n*3,i2+n*3,i2+n*2]
        cara4=[i1+n*3,i1+n*4,i2+n*4,i2+n*3]
        cara5=[i1+n*5,i1+n*6,i2+n*6,i2+n*5]
        listac+=[cara1,cara2,cara3,cara4,cara5]
        
        # Cristal
        #caraluz=[i1+n*4,i1+n*5,i2+n*5,i2+n*4] 
        #listaccristal+=[caraluz]
        
        caracristal1=[i*3,m+i*3,m+i*3+1,i*3+1]
        caracristal2=[i*3+1,m+i*3+1,m+i*3+2,i*3+2]
        caracristal3=[i*3+2,m+i*3+2,m+i*3,i*3]

        listaccristal+=[caracristal1,caracristal2,caracristal3]
        i+=1
    cara6=[19,18,17,16]
    cara7=[20,21,22,23]
    cara8=[27,26,25,24]
    listac+=[cara6,cara7,cara8]
    dibujar(listav,listac,pon_vectores_c(listav,listac),col,2,1,0)
    dibujar(listavcristal,listaccristal,pon_vectores_c(listavcristal,listaccristal),col,2,1,0)
    box(pos=c+w*(h2+h3+g/2.), size=(g/2.,g,g/2.), color=color.yellow, opacity=0.5)
    
##centrofarola=vector(0,-12,0)
##U=vector(1,0,0)
##V=vector(0,0,1)
##W=vector(0,1,0)
##rglorieta=20.0
##dglorieta=.5
##hglorieta=4
##h2glorieta=3
##nladosglorieta=8 
##farola(centrofarola,U,V,W,11.5,7,3,1.,color.white,color.yellow)
