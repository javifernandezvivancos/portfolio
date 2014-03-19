from visual import*

def vallaInterior(p0,p1,p2,p3,p00,p11,p22,p33,grosor,color1):
    u=vector(1,0,0)
    v=vector(0,0,1)
    w=vector(0,1,0)
    
    #Estructura
    cylinder(pos=p0,axis=p00-p0,radius=grosor,color=color1)
    cylinder(pos=p3,axis=p33-p3,radius=grosor,color=color1)
    cylinder(pos=p00,axis=p33-p00,radius=grosor,color=color1)
    cylinder(pos=p00,axis=p11-p00,radius=grosor,color=color1)
    cylinder(pos=p33,axis=p22-p33,radius=grosor,color=color1)
    
    #Valla
        #Parte izquierda
    #palo horizontal
    p4=p1+0.33333*(p0[1]-p1[1])*vector(0,1,0)
    p44=p11+0.4*(p00[1]-p2[1])*vector(0,1,0)
    cylinder(pos=p4,axis=p44-p4,radius=grosor,color=color1)
    #Palos diagonales
    pMitad=p4-.5*(p4[2]-p44[2])*v
    cylinder(pos=p1,axis=pMitad-p1,radius=grosor,color=color1)
    cylinder(pos=pMitad,axis=p11-pMitad,radius=grosor,color=color1)
    pMitad=pMitad-(pMitad[1]-p1[1])*w
    cylinder(pos=p4,axis=pMitad-p4,radius=grosor,color=color1)
    cylinder(pos=pMitad,axis=p44-pMitad,radius=grosor,color=color1)
        #Parte derecha
    #Palo horizontal
    p5=p4+(p3[0]-p4[0])*u
    p55=p44+(p33[0]-p44[0])*u
    cylinder(pos=p5,axis=p55-p5,radius=grosor,color=color1)
    #Palos diagonales
    pMitad=p5-.5*(p5[2]-p55[2])*v
    cylinder(pos=p2,axis=pMitad-p2,radius=grosor,color=color1)
    cylinder(pos=pMitad,axis=p22-pMitad,radius=grosor,color=color1)
    pMitad=pMitad-(pMitad[1]-p2[1])*w
    cylinder(pos=p5,axis=pMitad-p5,radius=grosor,color=color1)
    cylinder(pos=pMitad,axis=p55-pMitad,radius=grosor,color=color1)
        #Parte frontal
    #Palo horizontal
    cylinder(pos=p55,axis=p44-p55,radius=grosor,color=color1)
    #Palos diagonales
    pMitad=p44+0.25*(p55[0]-p44[0])*u
    pMitad2=pMitad+0.25*(p55[0]-p44[0])*u-(pMitad[1]-p1[1])*w
    cylinder(pos=pMitad,axis=p11-pMitad,radius=grosor,color=color1)
    cylinder(pos=pMitad,axis=pMitad2-pMitad,radius=grosor,color=color1)
    pMitad=pMitad+(2*(pMitad[0]-p0[0]))*u
    cylinder(pos=pMitad,axis=pMitad2-pMitad,radius=grosor,color=color1)
    cylinder(pos=pMitad,axis=p22-pMitad,radius=grosor,color=color1)
    pMitad=pMitad-(pMitad[1]-p2[1])*w
    cylinder(pos=pMitad,axis=p55-pMitad,radius=grosor,color=color1)
    pMitad2=pMitad2+(p5[1]-pMitad2[1])*w
    cylinder(pos=pMitad2,axis=pMitad-pMitad2,radius=grosor,color=color1)
    pMitad=pMitad+((2*(pMitad[0]-p2[0])))*u
    cylinder(pos=pMitad2,axis=pMitad-pMitad2,radius=grosor,color=color1)
    cylinder(pos=pMitad,axis=p44-pMitad,radius=grosor,color=color1)

    #Techo
    numPalos=40
    razon=(p3[0]-p0[0])/numPalos
    pi=p0
    pii=p00
    while(pi[0]<=p3[0]):
        cylinder(pos=pi,axis=pii-pi,radius=grosor,color=color1)
        pi=pi+razon*u
        pii=pii+razon*u
