def heapify(A,n,i):
    g=i
    l=i*2+1
    r=i*2+2
    if l<n and A[g]<A[l]:
        g=l
    if r<n and A[g]<A[r]:
        g=r
    if i!=g:
        A[i],A[g]=A[g],A[i]
        heapify(A,n,g)
        #print(A)
def non_recursive_heapify(A,n,current):
    cur=current
    while cur*2+1<n:
        l=cur*2+1
        r=cur*2+2
        if l<n and A[cur]<A[l]:
            cur=l
        if r<n and A[cur]<A[r]:
            cur=r
        if cur!=current:
            A[current],A[cur]=A[cur],A[current]
            current=cur
        else:
            break
            
if __name__=='__main__':
    B=[1,2,4,5,6]
    n=len(B)
    for i in range(n//2-1,-1,-1): 
        non_recursive_heapify(B,n,i)
        #print(B)

    
    for i in range(n-1,0,-1):
        B[i],B[0]=B[0],B[i]
        non_recursive_heapify(B,i,0)
        #print(B)
    print(B)

