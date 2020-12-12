def insertion_sort(A,n):
    for j in range(1,n):
        temp=A[j]
        i=j-1
        while i>=0 and A[i]>temp:
            A[i+1]=A[i]
            i-=1
            
        A[i+1]=temp
    print(A)

if __name__=='__main__':
    insertion_sort([5,4,3,2,1],5)
