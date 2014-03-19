from visual import*
def ventanaRedonda(posicion,radio,v,w,colorVigas):
    cylinder(pos=posicion,radius=radio,axis=0.25*radio*v,color=colorVigas)
    cylinder(pos=posicion-0.001*v,radius=0.75*radio,axis=0.25*radio*v+0.002*v,color=color.black)
    box(pos=posicion+0.25*radio*v*0.5,size=(radio*1.75,0.25*radio+0.005,0.25*radio+0.005),axis=w)

