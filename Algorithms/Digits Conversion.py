def binary_to_decimal(string) :
    binary = 0
    N = len(string)
    j = 0
    for i in range(N) :
        binary = binary + int(string[i])*2**(N-1-i)
    return binary

def binary_to_octal(string) :
    octal = ""
    N = len(string)
    p = int(N/3)
    for i in range(0,N,3) :
        binary = ''
        for j in range(i,i+3) :
            binary = binary + string[j]
        octal += str(binary_to_decimal(binary))
    return int(octal)

print(binary_to_octal("101001"))
print(binary_to_decimal("111001"))