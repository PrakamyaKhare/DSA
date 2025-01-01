import random

def matrix_mul(A,B) :
    C = [[0 for j in range(len(A))] for k in range(len(B[0]))]
    for row_a in range(len(A)) :
        for row_b in range(len(B)) :
            for k in range(len(A[0])) :
                C[row_a][k] = A[row_a][k]*B[k][row_b]
    return C

def print_matrix(A) :
    for i in range(len(A)) :
        print('[')
        for j in range(len(A[0])) :
            print(A[i][j],end='')
        print(']')

A = [[random.randint(1,10) for i in range(4)] for j in range(6)]
B = [[random.randint(1,10) for l in range(6)] for h in range(4)]
print_matrix(matrix_mul(A,B))