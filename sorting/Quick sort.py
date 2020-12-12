'''There are two ways of implementing quick sort actually
the only difference is the selection of pivot which changes the partition function
a little bit'''
#this approach  use pivot as first element
def partition(A,low,high):
    start=low
    end=high
    pivot=A[low]
    while start<end:
        while A[start]<=pivot:
            start+=1
        while A[end]>pivot:
            end-=1
        if start<end:
            A[start],A[end]=A[end],A[start]
    A[end],A[low]=A[low],A[end]
    return end

def Quick_sort(A,low,high):
    if low<high:
        loc=partition(A,low,high)
        Quick_sort(A,low,loc-1)
        Quick_sort(A,loc+1,high)

#this approach uses pivot as last element
def partition1(A,low,high):
    pivot=A[high]
    i=low-1
    for j in range(low,high):
        if A[j]<pivot:
            i=i+1
            A[i],A[j]=A[j],A[i]
    A[i+1],A[high]=A[high],A[i+1]
    return i+1

def Quick_sort1(A,low,high):
    if low<high:
        loc=partition1(A,low,high)
        Quick_sort1(A,low,loc-1)
        Quick_sort1(A,loc+1,high)

if __name__=='__main__':
    A=[10,25,10,24,46,23]
    low=0
    high=5
    #Quick_sort(A,low,high)
    Quick_sort(A,low,high)
    print(A)
    
    
    
        
