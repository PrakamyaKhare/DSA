def Max(arr,i):
    if i+1 == len(arr)-1 :
        return max(arr[i],arr[i+1])
    return max(arr[i],Max(arr,i+1))

A = [4,3,2,3,1]
print(Max(A,0))
