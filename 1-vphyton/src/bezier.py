from visual import *

def B(i,t):
    if i==0:
        return (1-t)**3
    if i==1:
        return 3*(1-t)**2*t
    if i==2:
        return 3*(1-t)*t**2
    if i==3:
        return t**3

def Bez(P0,P1,P2,P3,t):
    return B(0,t)*P0+B(1,t)*P1+B(2,t)*P2+B(3,t)*P3
