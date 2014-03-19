from visual import*

# Bezier
def B(i,t):
    if i==0:
        return (1-t)**3
    if i==1:
        return 3*(1-t)**2*t
    if i==2:
        return 3*(1-t)*t**2
    if i==3:
        return t**3
    
def Bez(p0,p1,p2,p3,t):
    return B(0,t)*p0+B(1,t)*p1+B(2,t)*p2+B(3,t)*p3

def Bezier(lista,t):
    ntrozos= 1+(len(lista)-4)/2
    trozo= int(t*ntrozos)
    if trozo>ntrozos-1:
        trozo= ntrozos-1
    if trozo==0:
        h0= lista[0]
        h1= lista[1]
        h2= lista[2]
        h3= lista[3]
    else:
        i= 3+(trozo-1)*2
        h0= lista[i]
        h1= 2*lista[i]-lista[i-1]
        h2= lista[i+1]
        h3= lista[i+2]
    s= t*ntrozos-trozo
    return Bez(h0,h1,h2,h3,s)

#Cat 

def CR0(s):
    return -.5*s**3+s**2-.5*s
def CR1(s):
    return 1.5*s**3-2.5*s**2+1
def CR2(s):
    return -1.5*s**3+2*s**2+.5*s
def CR3(s):
    return .5*s**3-.5*s**2

def CRom(lista,t):
    ntrozos=len(lista)-3
    trozo=int(t*ntrozos)
    if trozo>ntrozos-1:
        trozo=ntrozos-1
    i=trozo
    Q0=lista[i]
    Q1=lista[i+1]
    Q2=lista[i+2]
    Q3=lista[i+3]
    s=t*ntrozos-trozo
    return CR0(s)*Q0+CR1(s)*Q1+CR2(s)*Q2+CR3(s)*Q3
