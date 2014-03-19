from visual import*

def puerta(O,u,v,w,anchura,altura,profundidad,color1,color2):
    Oglobal=O
    O=O+0.5*profundidad*v
    box(pos=O,size=(anchura,altura,profundidad),axis=u,color=color1)
    O=O-u*anchura*0.214285+0.23*altura*w
    box(pos=O,size=(0.285714*anchura,0.4*altura,0.002+profundidad),axis=u,color=color.black)
    O=O+2*u*anchura*0.214285
    box(pos=O,size=(0.285714*anchura,0.4*altura,0.002+profundidad),axis=u,color=color.black)
    O=O-u*anchura*0.214285-0.23*altura*w
    #Pomo
    O=O+0.7*profundidad*v-0.30*u*anchura-0.05*altura*w
    sphere(pos=O,radius=0.07*anchura,color=color2)

