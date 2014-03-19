from visual import *
from lector import *
from curvas import *
from subrutinas import *
from curvas import *

lista=[]
lista0=[]
lista1=[]

def P_hoja(l1,l2,t,s):
    h=Bezier(l1,t)
    r=Bezier(l2,t)
    return (1-s)*h+s*r

def u_hoja(l1,l2,t,s):
    return norm(P_hoja(l1,l2,t+.001,s)-P_hoja(l1,l2,t,s))

def devs_hoja(l1,l2,t,s):
    return norm(P_hoja(l1,l2,t,s+.001)-P_hoja(l1,l2,t,s))

def w_hoja(l1,l2,t,s):
    return norm(cross(u_hoja(l1,l2,t,s),devs_hoja(l1,l2,t,s)))

#Palmera
def hoja_palmera(c,u,v,w,nramas,hramas):
    sphere(pos=c,radius=.5,color=(.7,.5,0))
    ug=u
    vg=v
    wg=w
    auxh=hramas/3.
    angg=2*pi/nramas
    i=0
    while i<nramas:
        p0=c+(.5)*vector(cos(angg*i),0,sin(angg*i))
        p1=p0+wg*auxh*2
        p2=p1+wg*auxh*2+ug*auxh
        p3=p1+ug*auxh*3

        curva=curve(radius=.02, color=(0,.6,0))
        inct=.01
        t=0
        while(t<=1):
            q=Bez(p0,p1,p2,p3,t)
            curva.append(pos=q)
            t+=inct

        inct = 1./100
        at=.75
        t = 0
        while (t<1):
            q = Bez(p0, p1, p2, p3, t)
            h = Bez(p0, p1, p2, p3, t+inct)
            r = .5*(q+h) + at*vg
            s = r - 2*(at*vg)
            convex(pos=[q,h,r,s], color=color.green)
            t = inct +t
            at = 0.99*at
            
        ug=norm(cos(angg)*ug+sin(angg)*vg)
        vg=cross(ug,w)
        i=i+1
        

def palmera_tronco(c,u,v,w,h,g,coltronco):
    incg=g/10.
    inch=h/10.
    base=c
    baseh=inch/4.
    baseg=g/1.25
    i=0
    while i<=4:
        cylinder(pos=base, radius=baseg, axis=vector(0,baseh,0), color=coltronco)
        i+=1
        baseg+=incg
        base+=w*baseh
        
    i=0
    while i<=9:
        cylinder(pos=base, radius=baseg, axis=vector(0,baseh,0), color=coltronco)
        i+=1
        baseg-=incg/1.5
        base+=vector(0,1,0)*baseh

def palmera(c,u,v,w,esc,htronco,gtronco,lbase,gbase,colbase,coltronco,coltierra):
    base_arbol(c,u,v,w,lbase*esc,lbase*esc,gbase*esc,colbase,coltierra)
    palmera_tronco(c,u,v,w,htronco*esc,gtronco*esc,coltronco)
    hoja_palmera(c,vector(1,0,0),vector(0,0,1),vector(0,1,0),6,2)
    
#palmera(vector(0,0,0),vector(1,0,0),vector(0,0,1),vector(0,1,0),1,5,1,4,.25,color.orange,(.7,.5,0),color.green)

#Arbol
def hoja(c,u,v,w,esc,l,a,colhoja):
    auxl=l/4.
    auxa=a/4.
    
    p0=c+u*esc*auxa+w*esc*auxa
    #sphere(pos=p0,radius=0.2,color=color.yellow)
    p1=p0+v*esc*a
    #sphere(pos=p1,radius=0.2,color=color.red)
    p2=p0+u*esc*auxl*2+v*esc*auxa*2-w*auxa
   # sphere(pos=p2,radius=0.2,color=color.red)
    p3=p0+u*esc*l
    #sphere(pos=p3,radius=0.2,color=colhoja)

    lista=[p0,p0+w*auxa,p0+u*esc*auxl*3,p3]
    lista0=[p0,p1,p2,p3]
    lista1=[p0,p1-v*esc*a*2,p2-v*esc*auxa*2*2,p3]
    
    #Tallo
    curve(pos=[c-w*1,p0],radius=0.03*esc,color=colhoja)

    #Borde hoja
##    npuntos=4
##    inct=1./npuntos
##    t=0
##    curva=curve(radius=0.01, color=colhoja)
##    curva0=curve(radius=0.01, color=colhoja)
##    curva1=curve(radius=0.01, color=colhoja)
##    while t<=1:
##        p=Bezier(lista,t)
##        curva.append(pos=p)
##        q=Bezier(lista0,t)
##        curva0.append(pos=q)
##        r=Bezier(lista1,t)
##        curva1.append(pos=r)
##        t+=inct

    #Suelo
    t0=0.
    t1=1.
    s0=0.
    s1=1.
    npuntost=11
    npuntoss=1
    inct=(t1-t0)/npuntost
    incs=(s1-s0)/npuntoss

    listap=[]
    listan=[]
    listap1=[]
    listan1=[]
    s=s0
    while s<s1+incs:
        filap=[]
        filan=[]
        filap1=[]
        filan1=[]
        t=t0
        while t<t1+inct:
            filap+=[P_hoja(lista0,lista,t,s)]
            filan+=[w_hoja(lista0,lista,t,s)]
            filap1+=[P_hoja(lista,lista1,t,s)]
            filan1+=[w_hoja(lista,lista1,t,s)]
            t+=inct
        listap+=[filap]
        listan+=[filan]
        listap1+=[filap1]
        listan1+=[filan1]
        s+=incs
        
    faces(pos=triangular(listap),normal=triangular(listan),color=colhoja)
    faces(pos=triangular(listap1),normal=triangular(listan1),color=colhoja)

def base_arbol(c,u,v,w,a,l,g,colb,coltierra):
    listav=[]
    listac=[]

    p0= c + (l/2.)*u + (l/2.)*v
    p1= c + (l/2.)*u - (l/2.)*v
    p2= c - (l/2.)*u - (l/2.)*v
    p3= c - (l/2.)*u + (l/2.)*v

    p4= p0  + g*w
    p5= p1 + g*w
    p6= p2 + g*w
    p7= p3 + g*w

    p8= c + (l/2.-g)*u + (l/2.-g)*v
    p9= c + (l/2.-g)*u - (l/2.-g)*v
    p10= c - (l/2.-g)*u - (l/2.-g)*v
    p11= c - (l/2.-g)*u + (l/2.-g)*v

    p12= p8 + g*w
    p13= p9 + g*w
    p14= p10 + g*w
    p15= p11 + g*w

    listav+=[p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15]
    cara0=[0,4,7,3]
    cara1=[3,7,6,2]
    cara2=[2,6,5,1]
    cara3=[1,5,4,0]
    cara4=[4,12,15,7]
    cara5=[7,15,14,6]
    cara6=[14,13,5,6]
    cara7=[4,5,13,12]
    cara8=[12,13,9,8]
    cara9=[12,8,11,15]
    cara10=[11,10,14,15]
    cara11=[9,13,14,10]
    listac+=[cara0,cara1,cara2,cara3,cara4,cara5,cara6,cara7,cara8,cara9,cara10,cara11]
    dibujar(listav,listac,pon_vectores_c(listav,listac),colb,2,1,0)
    convex(pos=[p8+w*.001,p9+w*.001,p10+w*.001,p11+w*.001],color=coltierra)


    ug=u
    vg=v
    angg=2*pi/8.
    i=0
    while i<=8:
        hoja(c+ug*1.25+w*.25,ug,vg,w,.3,2,1,color.green)
        ug=norm(cos(angg*i)*u+sin(angg*i)*v)
        vg=cross(ug,w)
        i=i+1

    

def arbol(c,u,v,w,lbase,gbase,colbase,coltierra):
    base_arbol(c,u,v,w,lbase,lbase,gbase,colbase,coltierra)
    hoja(c+w*7,u,v,w,1,4,2,color.green)
    cylinder(pos=c,color=(.7,.5,0),axis=(0,7,0), radius=.25)

#arbol(vector(0,0,0),vector(1,0,0),vector(0,0,1),vector(0,1,0),5,.5,color.red)
##i=0
##while i<10:
##    j=0
##    while j<10:
##        hoja(vector(i*3,0,j*2),vector(1,0,0),vector(0,0,1),vector(0,1,0),1,4,2,color.green)
##        j+=1
##    i+=1
    
