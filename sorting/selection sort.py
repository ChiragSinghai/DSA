def Selection_sort(A,n):
    for i in range(n-1):
        m=i+1
        for j in range(m+1,n):
            if A[m]>A[j]:
                m=j
        if A[m]<A[i]:
            A[i],A[m]=A[m],A[i]
    print(A)
    
if __name__=='__main__':
    Selection_sort([5,3,4,1,7,5],6)
            
