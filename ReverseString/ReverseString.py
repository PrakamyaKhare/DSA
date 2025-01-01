def reverse(st) :
    g = ''
    for i in range(len(st)-1,-1,-1) :
        g += st[i]
    return g
print(reverse('pinku'))

