def f(x) :
    if x <= 0 :
        return 0
    return 1

def check(nums,d=0) :

    digits = 10**(len(nums)-1)
    N = []
    pos = [0]*len(nums)
    found_sq1 = False
    non_palindrome = []
    found_sq2 = False
    for i in range(len(nums)) :
        n = m = p = q = 0
        n1 = []
        n2 = []
        for j in range(len(nums)-i) :
            n1.append(nums[i+j])
            n2.append(nums[j])
            n = n + nums[i+j]*10**(len(nums)-1 -i-j)
            m = m + nums[len(nums)-1-j]*10**(len(nums)-1-i-j)
            p = p + nums[j]*10**(len(nums)-1-i-j)
            q = q + nums[len(nums)-1-i-j]*10**(len(nums)-1-i-j)
        #print(n, " ",m)
        #print(p,' ',q)
        if found_sq1 and found_sq2 :
            break
        if p == q and not found_sq2:
            if len(n2) > 1 and not n2 in N:
              N.append(n2)
            found_sq2 = True
            if len(n2) == len(nums) :
                break
        if n == m and not found_sq1:
            found_sq1 = True
            if len(n1) > 1 and not n1 in N :
              N.append(n1)
            if len(n1) == len(nums) :
                break
            continue
        if d == 0 and len(nums) > len(n1) :
            temp1 = check(n1,d=d+1)
            if not temp1 :
                continue
            for t in temp1 :
                if t in N or len(t) <= 1:
                    continue
                N.append(t)
        if d == 0 and len(nums) > len(n2) :
            temp2 = check(n2,d=d+1)
            if not temp2 :
                continue
            for t in temp2 :
                if t in N or len(t) <= 1:
                    continue
                N.append(t)
    if N == [] and d == 0:
        return [[1]]*(len(nums)-1)
    return N


def partioning(s) :
    print(s)
    alpha = "abcdefghijklmnopqrstuvwxyz"
    dict_alpha = {}
    for a in range(len(alpha)) :
        dict_alpha[alpha[a]] = a+1
    num_alpha = []
    cache = []
    palindrome = []
    for char in s :
        num_alpha.append(dict_alpha[char])
    #print(num_alpha)
    return check(num_alpha)

#print(check([1,2,1,3,2,2]))
print(partioning("aab"))
print(partioning("a"))
print(partioning("abcd"))
print(partioning("abacdefghhhhhijkklmsaasohhh"))

if not [1,2,1] in [[1,2,1],[8,8,9]] :
    print('fukin yeah')
else :
    print('fukin no')