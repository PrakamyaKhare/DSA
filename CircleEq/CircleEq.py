import numpy as np
import matplotlib.pyplot as plt

def H(x,a) :
    return (a**2 - x**2)**0.5

def G(x,y,a) :
    return (a**2 - x**2 - y**2)**.5

ax = plt.figure().add_subplot(projection='3d')
X = []
Y = []
Z = []
a = 1
x = -a
dx = 0.01
y = 0
while x <= a :
    X.append(x)
    y = H(x,a)
    Y.append(y)
    Z.append([G(x,y,a)])
    x = x + dx
X = np.array(X)
Y = np.array(Y)
Z = np.array(Z)
surf = ax.plot_surface(X,Y,Z)
plt.show()



"""
a = 1
X = []
y = []
Y1 = []
x = -a
while x <= a :
    X.append(x-1)
    y.append(H(x-1,a))
    Y1.append(-1*H(x-1,a))
    x = x + 0.001
    
plt.plot(X,y)
plt.plot(X,Y1)
plt.show()
"""