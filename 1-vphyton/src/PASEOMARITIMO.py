from visual import *
from lector import *
from curvas import *
from subrutinas import *
from glorieta import *
from farola import *
from fuente import *
from fractales import *
from casa import *
from globo import *
from valla_fuente import *
from banco import *
from arbol import *
from palmera import *
from arena import *
from bandera import *
from sombrilla import *
from chiringuito import *
from mar import *
from acantilado import *
from parque import *
from subeBaja import *
from maceta import *
from avioneta import *
from random import *

#Ventana/Escena
#scene.fullscreen=0 # Pantalla Compelta
scene.autoescale=1 # zoom automatico
scene.background=color.cyan # Color de fondo
#scene.userspin=1 #quitar el movimiento del raton
scene.center=vector(0, 0, 0) #punto donde mira la camara
scene.forefround=color.white #color por defecto de los objetos

#Camara
scene.range=norm(vector(1,1,1))#controlar campo de vision 
yo=vector(-30,15,-30)
alfa=3*pi/2
beta=0
ucam=vector(cos(alfa)*cos(beta),sin(beta),sin(alfa)*cos(beta))
umov=vector(cos(alfa),0,sin(alfa))
vel=1
scene.center=yo-ucam
scene.forward=ucam

####
#### ZONA 1
####
##Glorieta
centroglorieta=vector(0,0,0)
U=vector(1,0,0)
V=vector(0,0,1)
W=vector(0,1,0)
rglorieta=20.0
dglorieta=.5
hglorieta=4
h2glorieta=3
nladosglorieta=8
vglorieta = glorieta(centroglorieta,U,V,W,rglorieta,dglorieta,hglorieta,h2glorieta,nladosglorieta,color.white)

####
#### ZONA 2
####
##Ramal Horizontal
lramalh = 60
vramalh = ramal(centroglorieta,U,V,W,pi/4,rglorieta,dglorieta,hglorieta,h2glorieta,lramalh,color.white)

####
#### ZONA 3 
####
##Ramal Vertical
ug=cos(pi/4)*U+sin(pi/4)*V
vg=cross(ug,W)
lramalv = 40
vramalv = ramal(centroglorieta-40*ug,ug,vg,W,pi/4+2*pi/2,rglorieta,dglorieta,hglorieta,h2glorieta,lramalv,color.white)

##Suelo glorieta y union ramales

union_ramales_glo(U,V,W,vglorieta,vramalh,vramalv,lramalh,lramalv,hglorieta,rglorieta)


####
#### ZONA 4 Arena
####

#Jardin
jardin0=vramalh[13] - W*.25
jardin2=vramalv[6] - W*.25
jardin1=vector(jardin0[0],0,jardin2[2]) + W*1.5
jardin3=vector(centroglorieta[0],jardin0[1],centroglorieta[2])
aux=vramalh[7]- W*8
jardin4=vector(vramalh[13][0],aux[1],vramalh[13][2])
jardin5=vector(jardin1[0],aux[1],jardin1[2])
jardin6=vector(jardin2[0],aux[1],jardin2[2])
listavaux=[jardin0,jardin1,jardin2,jardin3,jardin4,jardin5,jardin6]
cara1=[0,4,5,1]
cara2=[1,5,6,2]
cara3=[4,6,5]
cara=[0,1,2,3]
listacaux=[cara1,cara2,cara3,cara]
dibujar(listavaux,listacaux,pon_vectores_c(listavaux,listacaux),color.green,2,1,0)
# Playa
arena0=vramalh[7]+50*V-hglorieta/2.*W
arena1=vramalh[7]
arena2=vramalv[0]
arena3=vector(arena2[0],arena0[1],arena0[2])-hglorieta/1.5*W
poner_arena(U,V,W,arena0,arena1,arena2,arena3,2,0.5,(1,1,.3))

####
#### ZONA 5 Mar
####
# Agua
agua0=vramalh[7]+50*V-hglorieta*.7*W
agua2=vramalv[0]+75*V-hglorieta*.8*W
agua1=vector(agua0[0],agua2[1],agua2[2])
agua3=vector(agua2[0],agua0[1],agua0[2])-V*0.1+U*0.1

auxagua=arena3-W*3
agua4=vector(agua3[0],auxagua[1],agua3[2])
convex(pos=[agua0,agua3,agua4],color=color.blue)
convex(pos=[agua2,agua3,agua4],color=color.blue)
poner_mar(U,V,W,agua0,agua1,agua2,agua3,auxagua,color.blue)

####
#### Colocar Obajetos
####

## Poner farolas, bancos

def P_ponerFBA(iniciov,finv,inicioh,finh,t):
    return Bez(iniciov,finv,inicioh,finh,t)

def U_ponerFBA(iniciov,finv,inicioh,finh,t):
    return norm(P_ponerFBA(iniciov,finv,inicioh,finh,t)-P_ponerFBA(iniciov,finv,inicioh,finh,t+.001))

def V_ponerFBA(iniciov,finv,inicioh,finh,t):
    return norm(U_ponerFBA(iniciov,finv,inicioh,finh,t)-U_ponerFBA(iniciov,finv,inicioh,finh,t+.001))

def W_ponerFBA(iniciov,finv,inicioh,finh,t):
    return cross(U_ponerFBA(iniciov,finv,inicioh,finh,t),V_ponerFBA(iniciov,finv,inicioh,finh,t))


iniciov=(vramalv[6]+vramalv[5])/2
finv=(vramalv[12]+vramalv[13])/2
inicioh=(vramalh[6]+vramalh[5])/2
finh=(vramalh[12]+vramalh[13])/2

npuntos=12
inct=1./npuntos
t=0
turno=0
while t<=1:
    q=Bez(iniciov,finv,inicioh,finh,t)
    Uaux=U_ponerFBA(iniciov,finv,inicioh,finh,t)
    Vaux=V_ponerFBA(iniciov,finv,inicioh,finh,t)
    #Waux=W_ponerFBA(iniciov,finv,inicioh,finh,t)
    if turno==0:
        #farola(q,Uaux,Vaux,W,5.75,3.5,1.5,.5,color.green,color.yellow)
        farola(q,Uaux,Vaux,W,7,4.5,1.5,.60,(.2,.5,.5),color.yellow)
        turno+=1
    elif turno==1:
        #banco(q,U,V,W,10,5,4,1.75,1,.2,color.white)
        banco(q,Uaux,Vaux,W,5,2.5,2,0.875,.5,.1,(.7,.8,.5))#4876ff
        turno+=1
    elif turno==2:
        #(c,u,v,w,lbase,gbase,colbase)
        #arbol(q,Uaux,Vaux,W,4,.25,color.orange,color.green)
        palmera(q,Uaux,Vaux,W,1,7,1,4,.25,color.orange,(.7,.5,0),color.green)
        turno+=1
    else:
        banco(q,Uaux,Vaux,W,5,2.5,2,0.875,.5,.1,(.7,.8,.5))
        turno=0
    t+=inct

#macetero h
angg= 2*pi/4.
auxu= norm(cos(angg)*U+sin(angg)*V)
auxv= cross(auxu,W)
mh0= vramalh[5] - V*2 + U*10
maceta_planta(mh0,auxu,auxv,W,1,2.5,5,2,.1,color.white,color.green)
mh1= mh0 + U*15
maceta_planta(mh1,auxu,auxv,W,1,2.5,5,2,.1,color.white,color.green)
mh2= mh1 + U*15
maceta_planta(mh2,auxu,auxv,W,1,2.5,5,2,.1,color.white,color.green)
mh3= mh2 + U*15
maceta_planta(mh3,auxu,auxv,W,1,2.5,5,2,.1,color.white,color.green)

#macetero v
auxu=cos(pi/4.)*U+sin(pi/4.)*V
auxv=cross(auxu,W)
auxu=cos(pi/2.)*auxu+sin(pi/2.)*auxv
auxv=cross(auxu,W)

mh0= vramalv[5] + V*4 + U*6.5
maceta_planta(mh0,auxu,auxv,W,1,2.5,5,2,.1,color.white,color.green)
mh1= mh0 + V*10 + U*10
maceta_planta(mh1,auxu,auxv,W,1,2.5,5,2,.1,color.white,color.green)
mh2= mh1 + V*10 + U*10
maceta_planta(mh2,auxu,auxv,W,1,2.5,5,2,.1,color.white,color.green)

## Poner Fuente
fuente(7,10,centroglorieta+vector(0,2,0),U,W,V,color.red)
poligonoconvallas(centroglorieta+vector(0,2,0),8,pi/8,16,2,1,.5,0.5,.1,color.green)

#Bandera
bandera(vector(20,-1.5,20),U,V,W,1,15,.15,2,-4,color.white,color.green)

#Sombrillas
r=16
lista=[]
nlados=12
ang=2*pi/nlados
centroSombrillas=[vector(50,-1,40),vector(35,-1,35),vector(50,-1,50),vector(60,-1,45),vector(20,-1,35)]
i=0
while i<nlados:
    lista+=[vector(r*cos(i*ang),.1,r*sin(i*ang))]
    i+=1
nsombrillas=5
i=0
while i<nsombrillas:
    listar=[]
    j=0
    suma=0
    while j<nlados:
        s=random()
        listar+=[s]
        suma+=s
        j+=1
    listars=[]
    j=0
    while j<nlados:
        listars+=[2*listar[j]/suma]
        j+=1
    P=vector(0,-1,0)
    j=0
    while j<nlados:
        P+=listars[j]*lista[j]
        j+=1        
    angg=2*pi/(3+0.6*i)
    auxwg=norm(cos(angg)*U+sin(angg)*W)
    auxug=cross(auxwg,V)
    if i==0:
        col=color.blue
    elif i==1:
        col=color.red
    elif i==2:
        col=color.yellow
    elif i==3:
        col=color.green
    elif i==4:
        col=color.black
    else:
        col=color.white
        
    poner_sombrilla(P+centroSombrillas[i],auxug,V,auxwg,1,5,4,8,col,color.white)
    i+=1
##sphere(pos=vector(20,0,35),color=color.black)
##sphere(pos=vector(35,0,35),color=color.red)
##sphere(pos=vector(50,0,40),color=color.blue)
##sphere(pos=vector(50,0,60),color=color.yellow)
##sphere(pos=vector(60,0,50),color=color.green)
#chiringuito
posChiringuito= vector(60,-1,25)
chiringuito(9,7,7,posChiringuito,vector(1,0,0),vector(0,0,1),vector(0,1,0),color.orange)

#acantilado
p0=vector(23,-2,-55)
p1=p0+15*V
p2=p1+20*V
p3=p2+9*V
p4=p0+20*U
p5=p1+20*U+20*W
p6=p2+20*U+20*W
p7=p3+20*U
p8=p4+1*U
p9=p7-40*V+5*U
p10=p7-13*V+8*U
p11=p7+1*U
p12= p5+30*U
p13= p6+30*U
p14= p9+20*U
p15= p10+20*U
pon_acantilado(p0,p1,p2,p3,p4,p5,p6,p7,p8,p9,p10,p11,p12,p13,p14,p15)
#casa
pCasa= p5+ (0.5*(p6-p5)+0.5*(p13-p6)) +8*U -2.5*V
casa(14,15,11.6,15.1,pCasa,U,V,W,color.yellow,color.white,color.blue)
#globo
pGlobo= p5+ (0.5*(p6-p5)+0.5*(p13-p6)) -8*U
globo(10,10,pGlobo,U,W,V,color.yellow, color.orange, color.blue)
#Palmeras playa
palmera_clase(vector(30,-1,20),U,V,W,12.,2.,.5,6,.5,200,4.)
auxu = cos(pi/2)*U + sin(pi/2)*V
auxv = cross(auxu, W)
palmera_clase(vector(50,-1,20),auxu,auxv,W,10.,2.,.5,6,.5,200,4.)
auxu = cos(pi/2)*auxu + sin(pi/2)*auxv
auxv = cross(auxu, W)
palmera_clase(vector(-30,-1,-20),auxu,auxv,W,11.,2.,.5,6,.5,200,4.)

# Parque    
jaula(vector(-10,2,-50),U,V,W,1,9,0.1,color.red)

listap=[vector(-5,0,0),vector(0,0,0),vector(2,-1,0),vector(6,-2,0),vector(10,-6,0),vector(13,-8,0),vector(20,-8,0)]
auxu = cos(pi/2)*U + sin(pi/2)*V
auxv = cross(auxu, W)
tobogan(vector(0,2,-50),auxu,auxv,W,1,10,2,listap,0.05,color.red,color.yellow)
pSubeBaja=vector(14,2,-45)
subeBaja(pSubeBaja,U,V,W,.18,color.red,color.yellow,color.red)

Pavioneta= vector(0,40,80)
avioneta(3,Pavioneta,U,W,V,color.red,color.yellow,color.yellow,color.white)




# Movimiento camara teclas

while 1:
    tecla=scene.kb.getkey()
    if tecla=="left":
        alfa=alfa-0.1
    if tecla=="right":
        alfa=alfa+0.1
    if tecla=="up":
        yo=yo+vel*ucam
    if tecla=="down":
        yo=yo-vel*ucam
    if tecla=="x" and beta<pi/4:
        beta=beta+0.1
    if tecla=="z" and beta>-pi/4:
        beta=beta-0.1
    if tecla=="p":
        print yo
    ucam=vector(cos(alfa)*cos(beta),sin(beta),sin(alfa)*cos(beta))
    scene.center=yo+umov
    scene.forward=ucam


