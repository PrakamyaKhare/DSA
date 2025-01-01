
import numpy as np
import matplotlib.pyplot as plt


def fact(n) :
    if n == 1 :
        return 1
    return n*fact(n-1)

def Binomial(p,n,N) :
    return (fact(N)*p**n*(1 - p)**(N-n))/(fact(n)*fact(N-n))

print(Binomial(1/4,6,100))
