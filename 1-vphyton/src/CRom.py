from visual import *

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



