from visual import*
from lector import*
from random import*

def col(listap):
    listac= []
    for P in listap:
        if P[1]<=0:
            listac+= [color.green]
        if 0<P[1] and P[1]<=.5*25:
            s= 2.*P[1]/25
            listac+= [(1-s)*vector(color.green)+s*vector(.7,.5,0)]
        if P[1]>.5*25:
            s= 2.*P[1]/25
            listac+= [(1-s)*vector(.7,.5,0)+s*vector(1,1,1)]
    return listac

def ponCaras(malla):
    listac= []
    l= len(malla[0])
    i=0
    while i<len(malla)-1:
        j=0
        while j<len(malla[0])-1:
            cara= [j+l*i,j+1+i*l,j+1+(i+1)*l,j+(i+1)*l]
            listac+= [cara]
            j+= 1
        i+= 1
    listap= []
    for fila in malla:
            listap+= fila
    return [listap, listac]

def iterar(malla,d,h):
    malla2=[]
    for fila in malla:
        F=[]
        j=0
        while j<len(fila)-1:
            F+= [fila[j],.5*(fila[j]+fila[j+1])]
            j+= 1
        F+= [fila[j]]
        malla2+=[F]
        
    malla3= []
    i=0
    while i< len(malla)-1:
        malla3+= [malla2[i]]
        F= []
        j=0
        while j<len(malla2[0]):
            F+= [.5*(malla2[i][j]+malla2[i+1][j])]
            j+= 1
        malla3+= [F]
        i+= 1
    malla3+= [malla2[i]]

    malla4=[]
    i=0
    while i<len(malla3):
        F=[]
        j=0
        while j<len(malla3[0]):
            if i==0 or i==len(malla3)-1 or j==0 or j==len(malla3[0])-1:
                F+= [malla3[i][j]]
            else:
                F+= [malla3[i][j]+vector(-d+2*random()*d,-h+2*random()*h,-d+2*random()*d)]
            j+=1
        malla4+= [F]
        i+=1
    return malla4                                                    


#p0=vector(-20,0,20)
#p1=vector(0,0,20)
#p2=vector(20,0,20)
#p3=vector(-20,0,0)
#p4=vector(0,20,0)
#p5=vector(20,0,0)
#p6=vector(-20,0,-20)
#p7=vector(0,0,-20)
#p8=vector(20,0,-20)

#malla= [[p0,p1,p2],[p3,p4,p5],[p6,p7,p8]]
#h=10.
#d=2.
#suav=3
#i=0
#while i<6:
#    malla= iterar(malla)
#    h= h/suav
#    d= d/suav
#    i+=1
#lista= ponCaras(malla)

#dibujar(lista[0],lista[1],pon_vectores_c(lista[0],lista[1]),(.7,.5,0),2,1,0)
#dibujar(lista[0],lista[1],pon_vectores_c(lista[0],lista[1]),col(lista[0]),0,1,0)


