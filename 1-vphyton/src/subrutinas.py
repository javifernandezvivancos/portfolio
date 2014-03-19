from visual import *

def triangular(lista):
    listado=[]
    nfilas=len(lista)
    ncolumnas=len(lista[0])
    i=0
    while i<nfilas-1:
        j=0
        while j<ncolumnas-1:
            listado=listado+[lista[i][j],lista[i][j+1],lista[i+1][j]]
            listado=listado+[lista[i][j],lista[i+1][j],lista[i][j+1]]#borrar este si no quieres ver triangulos interiores
            
            listado=listado+[lista[i][j+1],lista[i+1][j+1],lista[i+1][j]]
            listado=listado+[lista[i][j+1],lista[i+1][j],lista[i+1][j+1]]#borrar este si no quieres ver triangulos interiores
            j+=1
        i+=1
    return listado


def curva(lista,r1,r2,col,nlados,aini):
    ang=2*pi/nlados
    listap=[]
    listan=[]
    i=0
    while i<len(lista)-1:
        P=lista[i]
        Q=lista[i+1]
        w=norm(Q-P)
        if mag(vector(w[0],0,w[1]))<.0001:
            u=vector(1,0,0)
            v=vector(0,0,1)
        else:
            u=norm(cross(w,vector(0,1,0)))
            v=cross(w,u)
        if i==0:
            lista1=[]
            lista2=[]
            listan1=[]
            listan2=[]
            j=0
            while j<nlados:
                lista1+=[P+r1*cos(j*ang+aini)*u+r2*sin(j*ang+aini)*v]
                lista2+=[Q+r1*cos(j*ang+aini)*u+r2*sin(j*ang+aini)*v]
                listan1+=[r1*cos(j*ang+aini)*u+r2*sin(j*ang+aini)*v]
                listan2+=[r1*cos(j*ang+aini)*u+r2*sin(j*ang+aini)*v]
                j+=1
        else:
            lista1=lista2
            listan1=listan2
            lista2=[]
            listan2=[]
            j=0
            while j<nlados:
                lista2+=[Q+r1*cos(j*ang+aini)*u+r2*sin(j*ang+aini)*v]
                listan2+=[r1*cos(j*ang+aini)*u+r2*sin(j*ang+aini)*v]
                j+=1
        j=0
        while j<len(lista1):
            listap+=[lista1[j],lista1[(j+1)%(len(lista1))],lista2[(j+1)%(len(lista1))]]
            listap+=[lista1[j],lista2[(j+1)%(len(lista1))],lista1[(j+1)%(len(lista1))]]
            listan+=[listan1[j],listan1[(j+1)%(len(lista1))],listan2[(j+1)%(len(lista1))]]
            listan+=[listan1[j],listan2[(j+1)%(len(lista1))],listan1[(j+1)%(len(lista1))]]
            listap+=[lista1[j],lista2[(j+1)%(len(lista1))],lista2[j]]
            listan+=[listan1[j],listan2[(j+1)%(len(lista1))],listan2[j]]
            listap+=[lista1[j],lista2[j],lista2[(j+1)%(len(lista1))]]
            listan+=[listan1[j],listan2[j],listan2[(j+1)%(len(lista1))]]
            j+=1
        i+=1
    faces(pos=listap,normal=listan,color=col)


##lista=[]
##t=0
##while t<2*pi:
##    lista+=[vector(t*cos(t),t,t*sin(t))]
##    t+=.1
##curva(lista,1,1,color.red,12,0)

