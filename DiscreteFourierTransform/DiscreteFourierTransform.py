import math

def fourier_matrix(N) :
    F_N = [[1 for n in range(N)]for i in range(N)]
    e = 2.71828182
    PI = 3.1415926535897932384626433832795028841971693993751058209749445923078164
    x = 2*PI/N
    E = math.cos(x) - complex(1)*math.sin(x)
    for i in range(N) :
        for j in range(N) :
            F_N[i][j] = E**(i*j)
    return F_N


def frequency_spectrum(f) :
    N = len(f)
    F_N = fourier_matrix(N)
    f_hat = [0 for i in range(N)]
    for i in range(N) :
        for j in range(N) :
            f_hat[i] += F_N[i][j]*f[j]
    return f_hat
            

print(complex(1))
print(fourier_matrix(4))
print(frequency_spectrum([0,1,4,9]))
            