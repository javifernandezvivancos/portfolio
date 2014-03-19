from visual import *
from curvas import *
from subrutinas import *

def Pto(l1,l2,t,s):
    h=CRom(l1,t)
    r=CRom(l2,t)
    return (1-s)*h+s*r

def uto(l1,l2,t,s):
    return norm(Pto(l1,l2,t+.001,s)-Pto(l1,l2,t,s))

def devsto(l1,l2,t,s):
    return norm(Pto(l1,l2,t,s+.001)-Pto(l1,l2,t,s))

def wto(l1,l2,t,s):
    return norm(cross(uto(l1,l2,t,s),devsto(l1,l2,t,s)))

def tobogan(c,u,v,w,esc,h,a,listap,g,col1,col2):
    h=h*esc
    a=a*esc
    oct_h=h/8.
    mitad_a=a/1.
    
    escalera_d0= c - u*mitad_a
    escalera_d1= escalera_d0 + w*oct_h
    escalera_d2= escalera_d1 + w*oct_h
    escalera_d3= escalera_d2 + w*oct_h
    escalera_d4= escalera_d3 + w*oct_h
    escalera_d5= escalera_d4 + w*oct_h
    escalera_d6= escalera_d5 + w*oct_h
    escalera_d7= escalera_d6 + w*oct_h

    escalera_i0= escalera_d0 - v*a
    escalera_i1= escalera_d1 - v*a
    escalera_i2= escalera_d2 - v*a
    escalera_i3= escalera_d3 - v*a
    escalera_i4= escalera_d4 - v*a
    escalera_i5= escalera_d5 - v*a
    escalera_i6= escalera_d6 - v*a
    escalera_i7= escalera_d7 - v*a

    curve(pos=[escalera_d0,escalera_d7,escalera_i7,escalera_i0],color=col1)
    curve(pos=[escalera_d0,escalera_d7,escalera_i7,escalera_i0],color=col1)
    curve(pos=[escalera_d1,escalera_i1],color=col1)
    curve(pos=[escalera_d2,escalera_i2],color=col1)
    curve(pos=[escalera_d3,escalera_i3],color=col1)
    curve(pos=[escalera_d4,escalera_i4],color=col1)
    curve(pos=[escalera_d5,escalera_i5],color=col1)
    curve(pos=[escalera_d6,escalera_i6],color=col1)
    curve(pos=[escalera_d7,escalera_i7],color=col1)

    ini1= escalera_i7 + w*(a/4.)
    ini2= escalera_i7
    ini3= escalera_d7
    ini4= escalera_d7 + w*(a/4.)
    
    l1=[]
    l2=[]
    l3=[]
    l4=[]

    for i in listap:
        l1+=[ini1 + i[0]*u + i[1]*w + i[2]*v]
        l2+=[ini2 + i[0]*u + i[1]*w + i[2]*v]
        l3+=[ini3 + i[0]*u + i[1]*w + i[2]*v]
        l4+=[ini4 + + i[0]*u + i[1]*w + i[2]*v]

    t0=0.
    t1=1.
    s0=0.
    s1=1.
    npuntost=100
    npuntoss=2
    inct=(t1-t0)/npuntost
    incs=(s1-s0)/npuntoss

    listap=[]
    listan=[]
    listap1=[]
    listan1=[]
    listap2=[]
    listan2=[]
    s=s0
    while s<s1+incs:
        filap=[]
        filan=[]
        filap1=[]
        filan1=[]
        filap2=[]
        filan2=[]
        t=t0
        while t<t1+inct:
            filap+=[Pto(l1,l2,t,s)]
            filan+=[wto(l1,l2,t,s)]
            filap1+=[Pto(l2,l3,t,s)]
            filan1+=[wto(l2,l3,t,s)]
            filap2+=[Pto(l3,l4,t,s)]
            filan2+=[wto(l3,l4,t,s)]
            t+=inct
        listap+=[filap]
        listan+=[filan]
        listap1+=[filap1]
        listan1+=[filan1]
        listap2+=[filap2]
        listan2+=[filan2]
        s+=incs
    faces(pos=triangular(listap),normal=triangular(listan),color=col1)
    faces(pos=triangular(listap1),normal=triangular(listan1),color=col2)
    faces(pos=triangular(listap2),normal=triangular(listan2),color=col1)

    curve(pos=[l2[len(l2)-2],l2[len(l2)-2]+w*-2], radius=g*esc, color=col1)
    curve(pos=[l3[len(l3)-2],l3[len(l2)-2]+w*-2], radius=g*esc, color=col1)

    
    
    

def jaula(c,u,v,w,esc,ancho,g,col):
    g=g*esc
    tercio_a=(ancho/3.)*esc
    sexto_a=(tercio_a/2.)*esc
    c=c+w*(g/2.)
    #Base
    p0=c + u*sexto_a + v*sexto_a
    p1=c + u*sexto_a - v*sexto_a
    p2=c - u*sexto_a - v*sexto_a
    p3=c - u*sexto_a + v*sexto_a
    sphere(pos=p0,radius=g,color=col)
    sphere(pos=p1,radius=g,color=col)
    sphere(pos=p2,radius=g,color=col)
    sphere(pos=p3,radius=g,color=col)
    p4= p0 + u*tercio_a + v*tercio_a
    p5= p0 + u*tercio_a
    sphere(pos=p4,radius=g,color=col)
    sphere(pos=p5,radius=g,color=col)
    p6= p1 + u*tercio_a
    p7= p1 + u*tercio_a - v*tercio_a
    p8= p1 - v*tercio_a
    sphere(pos=p6,radius=g,color=col)
    sphere(pos=p7,radius=g,color=col)
    sphere(pos=p8,radius=g,color=col)
    p9= p2 - v*tercio_a
    p10= p2 - u*tercio_a - v*tercio_a
    p11= p2 - u*tercio_a
    sphere(pos=p9,radius=g,color=col)
    sphere(pos=p10,radius=g,color=col)
    sphere(pos=p11,radius=g,color=col)
    p12= p3 - u*tercio_a
    p13= p3 - u*tercio_a + v*tercio_a
    p14= p3 + v*tercio_a
    sphere(pos=p12,radius=g,color=col)
    sphere(pos=p13,radius=g,color=col)
    sphere(pos=p14,radius=g,color=col)
    p15= p0 + v*tercio_a
    sphere(pos=p15,radius=g,color=col)
    
    #Nivel 1
    q0=p0 + w*tercio_a
    q1=p1 + w*tercio_a
    q2=p2 + w*tercio_a
    q3=p3 + w*tercio_a
    q4=p4 + w*tercio_a
    q5=p5 + w*tercio_a
    q6=p6 + w*tercio_a
    q7=p7 + w*tercio_a
    q8=p8 + w*tercio_a
    q9=p9 + w*tercio_a
    q10=p10 + w*tercio_a
    q11=p11 + w*tercio_a
    q12=p12 + w*tercio_a
    q13=p13 + w*tercio_a
    q14=p14 + w*tercio_a
    q15=p15 + w*tercio_a
    
    sphere(pos=q0,radius=g,color=col)
    sphere(pos=q1,radius=g,color=col)
    sphere(pos=q2,radius=g,color=col)
    sphere(pos=q3,radius=g,color=col)
    sphere(pos=q4,radius=g,color=col)
    sphere(pos=q5,radius=g,color=col)
    sphere(pos=q6,radius=g,color=col)
    sphere(pos=q7,radius=g,color=col)
    sphere(pos=q8,radius=g,color=col)
    sphere(pos=q9,radius=g,color=col)
    sphere(pos=q10,radius=g,color=col)
    sphere(pos=q11,radius=g,color=col)
    sphere(pos=q12,radius=g,color=col)
    sphere(pos=q13,radius=g,color=col)
    sphere(pos=q14,radius=g,color=col)
    sphere(pos=q15,radius=g,color=col)



    #Nivel 2
    r0=q0 + w*tercio_a
    r1=q1 + w*tercio_a
    r2=q2 + w*tercio_a
    r3=q3 + w*tercio_a
    r4=q4 + w*tercio_a
    r5=q5 + w*tercio_a
    r6=q6 + w*tercio_a
    r7=q7 + w*tercio_a
    r8=q8 + w*tercio_a
    r9=q9 + w*tercio_a
    r10=q10 + w*tercio_a
    r11=q11 + w*tercio_a
    r12=q12 + w*tercio_a
    r13=q13 + w*tercio_a
    r14=q14 + w*tercio_a
    r15=q15 + w*tercio_a
    
    sphere(pos=r0,radius=g,color=col)
    sphere(pos=r1,radius=g,color=col)
    sphere(pos=r2,radius=g,color=col)
    sphere(pos=r3,radius=g,color=col)
    sphere(pos=r4,radius=g,color=col)
    sphere(pos=r5,radius=g,color=col)
    sphere(pos=r6,radius=g,color=col)
    sphere(pos=r7,radius=g,color=col)
    sphere(pos=r8,radius=g,color=col)
    sphere(pos=r9,radius=g,color=col)
    sphere(pos=r10,radius=g,color=col)
    sphere(pos=r11,radius=g,color=col)
    sphere(pos=r12,radius=g,color=col)
    sphere(pos=r13,radius=g,color=col)
    sphere(pos=r14,radius=g,color=col)
    sphere(pos=r15,radius=g,color=col)

    s0=r0 + w*tercio_a
    s1=r1 + w*tercio_a
    s2=r2 + w*tercio_a
    s3=r3 + w*tercio_a

    sphere(pos=s0,radius=g,color=col)
    sphere(pos=s1,radius=g,color=col)
    sphere(pos=s2,radius=g,color=col)
    sphere(pos=s3,radius=g,color=col)



    curve(pos=[p4,p7,p10,p13,p4],radius=g,color=col)
    curve(pos=[q4,q7,q10,q13,q4],radius=g,color=col)
    curve(pos=[r4,r7,r10,r13,r4],radius=g,color=col)
    curve(pos=[s0,s1,s2,s3,s0],radius=g,color=col)
    
    curve(pos=[p5,r5,r12,p12,p5],radius=g,color=col)
    curve(pos=[p6,r6,r11,p11,p6],radius=g,color=col)

    curve(pos=[p15,r15,r8,p8,p15],radius=g,color=col)
    curve(pos=[p14,r14,r9,p9,p14],radius=g,color=col)

    
    curve(pos=[p0,s0],radius=g,color=col)
    curve(pos=[p1,s1],radius=g,color=col)
    curve(pos=[p2,s2],radius=g,color=col)
    curve(pos=[p3,s3],radius=g,color=col)
    curve(pos=[p4,r4],radius=g,color=col)
    curve(pos=[p7,r7],radius=g,color=col)
    curve(pos=[p10,r10],radius=g,color=col)
    curve(pos=[p13,r13],radius=g,color=col)
    


##U=vector(1,0,0)
##V=vector(0,0,1)
##W=vector(0,1,0)
##jaula(vector(0,0,0),U,V,W,1,9,0.1,color.red)

#listap=[vector(-5,0,0),vector(0,0,0),vector(2,-1,0),vector(6,-2,0),vector(10,-6,0),vector(13,-8,0),vector(20,-8,0)]
#tobogan(vector(0,0,0),U,V,W,1,10,2,listap,color.red,color.yellow)
    
