def square(x) :
    return x*x

def F(H,T) :
    """
    The percentage of the powder that becomes extracted pectin is given by this function :- F(H,T)
    pectin is a material that extracted from pineapples peels.
    """
    return -0.042*square(T) - 0.213*T*H - 11.219*square(H) + 7.327*T + 58.729*H - 342.684

print(F(2.19,81.672))
print(F(0,87.22))
print(F(1.5,0))
print(F(1.5,70))
print(F(0,2.5))
print(F(2.5,90))

import math
print(150*math.cos(10)+100*math.cos(15))