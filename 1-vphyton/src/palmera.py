from visual import *
from curvas import *


def palmera_clase(p,u,v,w,h,a,g,lhoja,hhoja,ntriangulos,at):

    p0 = p
    p1 = p0 +.5*h*w
    p2 = p0 + .5*a*u + .5*h*w
    p3 = p0 + a*u + h*w

    curva = curve()
    inct = .01
    t=0

    while (t<1):
        q = Bez(p0, p1, p2, p3, t)
        curva.append(pos=q)
        t+=inct

    ntroncos = 10
    inct = 1./ntroncos
    t = 0

    while(t<1):
        q = Bez(p0, p1, p2, p3, t)
        h = Bez(p0, p1, p2, p3, t+inct)
        cylinder(pos = q, radius = g, axis = h-q, color= (.7,.5,0))
        t += inct
        g = .9*g
    
    wt = norm(h-q)
    ut = norm(cross(wt, vector(1,0,0)))
    vt = cross(ut,wt)

    nhojas = 9

    ang = 2*pi/nhojas
    i =0
    while(i<nhojas):
        uh = cos(i*ang)*ut + sin(i*ang)*vt
        vh = cross(uh, wt)
        hojaPalmera(h,uh,vh,wt,lhoja,hhoja,ntriangulos,at)
        i+=1
    
    
def hojaPalmera(p,u,v,w,l,h,ntriangulos,at):
    p0 = p
    p3 = p + l*u
    p1 = p + .3*l*u + 3*h*w
    p2 = p + .7*l*u + 3*h*w

    curva = curve(radius = .1, color=(0,.6,0))
    inct = .01
    t=0
    while(t<1):
        q = Bez(p0, p1, p2, p3, t)
        curva.append(pos=q)
        t+=inct

    inct = 1./ntriangulos
    t = 0
    while (t<1):
        q = Bez(p0, p1, p2, p3, t)
        h = Bez(p0, p1, p2, p3, t+inct)
        vh = norm(cross(h-q, w))
        r = .5*(q+h) + at*vh
        s = r - 2*(at*vh)
        convex(pos=[q,h,r,s], color=color.green)
        t = inct +t
        at = 0.99*at
##        
##        
##
##
##o = vector(0,0,0)
##u = vector(1,0,0)
##v = vector(0,0,1)
##w = vector(0,1,0)
##
##i=0
##ang = 2*pi/10
##palmera(o,u,v,w,10.,2.,.5,6,.5,200,4.)
##while(i<10):
##    uh = cos(i*ang)*u + sin(i*ang)*v
##    vh = cross(uh, w)
##    o = o + i*uh + i*vh
##    palmera(o,uh,vh,w,10.,2.,.5,6,.5,200,4.)
##
##    
##    i +=1
##    
