from visual import *
from lector import *
from curvas import *

def tallo_maceta(c,u,v,w,a,h,g,col):

    p0=c
    p1=p0 + (h/2.)*w
    p2=p1 + (a/3.)*v + (h/2.)*w
    p3=p2 + (a/2.)*v + (h/2.)*w
    
##    sphere(pos=p0, radius=0.1,color=color.red)
##    sphere(pos=p1, radius=0.1,color=color.red)
##    sphere(pos=p2, radius=0.1,color=color.red)
##    sphere(pos=p3, radius=0.1,color=color.red)

    curva=curve(radius=.02, color=col)
    inct=.01
    t=0
    while(t<=1):
        q=Bez(p0,p1,p2,p3,t)
        curva.append(pos=q)
        t+=inct

def macetero(c,u,v,w,a,l,h,pico,col,col2):
    listav=[]
    listac=[]

    p0= c + ((a-pico)*1./2)*u + ((l-pico)*1./2)*v + pico*w
    p1= c + ((a-pico)*1./2)*u - ((l-pico)*1./2)*v + pico*w
    p2= c - ((a-pico)*1./2)*u - ((l-pico)*1./2)*v + pico*w
    p3= c - ((a-pico)*1./2)*u + ((l-pico)*1./2)*v + pico*w
    
    p4= c + (a*1./2)*u + (l*1./2)*v  + pico*2*w
    p5= c + (a*1./2)*u - (l*1./2)*v  + pico*2*w
    p6= c - (a*1./2)*u - (l*1./2)*v  + pico*2*w
    p7= c - (a*1./2)*u + (l*1./2)*v  + pico*2*w
    p8= p4 + h*w
    p9= p5 + h*w
    p10= p6 + h*w
    p11= p7 +h*w
    p12= c + ((a-pico*3)*1./2)*u + ((l-pico*3)*1./2)*v + h*w
    p13= c + ((a-pico*3)*1./2)*u - ((l-pico*3)*1./2)*v + h*w
    p14= c - ((a-pico*3)*1./2)*u - ((l-pico*3)*1./2)*v + h*w
    p15= c - ((a-pico*3)*1./2)*u + ((l-pico*3)*1./2)*v + h*w
    p16= p12 - (pico*4)*w
    p17= p13 - (pico*4)*w
    p18= p14 - (pico*4)*w
    p19= p15 - (pico*4)*w

    listav+=[p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15,p16,p17,p18,p19]
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
    cara10=[9,10,14,13]
    cara11=[10,11,15,14]
    cara12=[8,12,15,11]
    cara13=[12,13,17,16]
    cara14=[13,14,18,17]
    cara15=[14,15,19,18]
    cara16=[15,12,16,19]
    
    convex(pos=[p16,p17,p18,p19],color=col2)
    listac+=[cara0,cara1,cara2,cara3,cara4,cara5,cara6,cara7,cara8,cara9,cara10,cara11,cara12,cara13,cara14,cara15,cara16]
    dibujar(listav,listac,pon_vectores_c(listav,listac),col,2,1,0)
    cylinder(pos=c,radius=(a/2.)-pico,axis=(0,pico,0),color=col)

    auxc= (p16 + p17 + p18 + p19)/4.
    auxc0= auxc-v*(a/2.)
    auxc1= auxc-v*(a/4.)
    auxc2= auxc+v*(a/4.)
    auxc3= auxc+v*(a/2.)

##    sphere(pos=auxc0)
##    sphere(pos=auxc1)

    ug=u
    vg=v
    angg=2*pi/8.
    i=0
    while i<=8:
        tallo_maceta(auxc0+ug*0.25,ug,vg,w,a*.3,h*.8,pico/2.,col2)
        ug=norm(cos(angg*i)*u+sin(angg*i)*v)
        vg=cross(ug,w)
        i=i+1

    ug=u
    vg=v
    angg=2*pi/8.
    i=0
    while i<=8:
        tallo_maceta(auxc1+ug*0.25,ug,vg,w,a*.3,h*.8,pico/2.,col2)
        ug=norm(cos(angg*i)*u+sin(angg*i)*v)
        vg=cross(ug,w)
        i=i+1

    ug=u
    vg=v
    angg=2*pi/8.
    i=0
    while i<=8:
        tallo_maceta(auxc+ug*0.25,ug,vg,w,a*.3,h*.8,pico/2.,col2)
        ug=norm(cos(angg*i)*u+sin(angg*i)*v)
        vg=cross(ug,w)
        i=i+1

    ug=u
    vg=v
    angg=2*pi/8.
    i=0
    while i<=8:
        tallo_maceta(auxc2+ug*0.25,ug,vg,w,a*.3,h*.8,pico/2.,col2)
        ug=norm(cos(angg*i)*u+sin(angg*i)*v)
        vg=cross(ug,w)
        i=i+1

    ug=u
    vg=v
    angg=2*pi/8.
    i=0
    while i<=8:
        tallo_maceta(auxc3+ug*0.25,ug,vg,w,a*.3,h*.8,pico/2.,col2)
        ug=norm(cos(angg*i)*u+sin(angg*i)*v)
        vg=cross(ug,w)
        i=i+1
        
    
    
    

def maceta_planta(c,u,v,w,esc,am,lm,hm,pico,col,col2):
    macetero(c,u,v,w,am*esc,lm*esc,hm*esc,pico*esc,col,col2)
    
#maceta_planta(vector(0,0,0),vector(1,0,0),vector(0,0,1),vector(0,1,0),1,5,10,4,.2,color.white,color.green)
