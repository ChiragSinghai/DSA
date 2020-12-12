def merge(A,start,mid,end):
    temp=[0 for i in range(end-start+1)]
    i,j,k=start,mid+1,0
    while i<=mid and j <=end:
        if A[i]<=A[j]:
            temp[k]=A[i]
            i+=1
            
        else:
            temp[k]=A[j]
            j+=1
        k+=1
    while i<=mid:
        temp[k]=A[i]
        i+=1
        k+=1
    while j<=end:
        temp[k]=A[j]
        j+=1
        k+=1

    for i in range(start,end+1):
        A[i]=temp[i-start]

def merge_sort1(A,start,end):
    if start<end:
        mid=(start+end)//2
        merge_sort(A,start,mid)
        merge_sort(A,mid+1,end)
        merge(A,start,mid,end)

def merge_sort(A):
    if len(A)>1:
        mid=len(A)//2
        L=A[:mid]
        R=A[mid:]
        merge_sort(L)
        merge_sort(R)
        i=j=k=0
        while i<len(L) and j<len(R):
            if L[i]<R[j]:
                A[k]=L[i]
                i+=1
            else:
                A[k]=R[j]
                j+=1
            k+=1
        while i<len(L):
            A[k]=L[i]
            i+=1
            k+=1
        while j <len(R):
            A[k]=R[j]
            j+=1
            k+=1
        


    
if __name__=='__main__':
    A=[12,32,11,10,15,23,17]
    start=0
    end=len(A)-1
    merge_sort(A)
    
    #merge_sort1(A,start,end)
    print(A)
    
    
    
