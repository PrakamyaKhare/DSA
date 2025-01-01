def CMP(a,b) :
    c = b - (a * a)
    if c < 0.001 :
        return True
    return False

def INT(n) :
    n = str(n)
    if not '.' in n :
        return int(n)
    d = n.split('.')[1]
    if int(d[0]) + int(d[1]) >= 18 :
        return int(float(n)) + 1
    return int(float(n))

def sqrt(n) :
    if 0 <= n <= 1 :
        return n
    if 2 <= n <= 3 :
        return 1
    m = 0
    x = 2
    if n >= 100 :
        m = int(n/5)
    else :
        m = int(n/2)
    while x <= m :
        if CMP(x,n) :
            return x
        x = x + 0.00001
    return x

print(sqrt(2))