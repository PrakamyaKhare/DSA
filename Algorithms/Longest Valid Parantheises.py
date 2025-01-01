def sum_(arr) :
    s = 0
    for a in arr :
        s = s + a
    return s

def maximum(arr) :
    s = 0
    for i in range(len(arr)) :
        if arr[i] > s :
            s = arr[i]
    return s

def f(s) :
    lvp = []
    open = []
    sep = []
    l = 0
    using_lvp = False
    gap = 0
    summed = 0
    for  i in range(len(s)) :
        if s[i] == '(' :
            open.append("(")
        elif s[i] == ')' :
            if i == 0 :
                continue
            if len(open) == 0 :
                gap = gap + 1
                s_s = sum_(sep)
                sep.clear()
                sep.append(s_s)
                l = 0
                using_lvp = True
                continue
            open.pop()
            if len(open) == 0 and using_lvp == False :
                sep.append(1)
                l = 0
                continue
            else :
                using_lvp = True
                l = l + 1
                lvp.append(l)
            if len(open) == 0 :
                if gap == 0 :
                    summed = (2*maximum(lvp) + 2*sum_(sep))
                    lvp = []
                    sep = []
                using_lvp = False
    
    s_ = 2*sum_(sep)
    m = 2*maximum(lvp)
    print([s_,m,summed])
    return maximum([s_,m,summed+s_])

print(f("()(()())"))
print(f("()(())"))
print(f("()))()))))))"))
print(f("()(()))"))
print(f("()(())))())"))
print(f(")()())"))
print(f("()()))(())()"))
print(f("((()))())"))
print(f(")()())()()("))