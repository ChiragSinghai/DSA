def Bubble_sort(A):
    print('Before Sorting',A)
    n=len(A)
    for i in range(n):
        for j in range(0,n-i-1):
            if A[j]>A[j+1]:
                A[j],A[j+1]=A[j+1],A[j]
    print('After sorting',A)
def optimised_bubble(A):
    print('Before Sorting',A)
    n=len(A)
    for i in range(n):
        swapped=False
        for j in range(0,n-i-1):
            if A[j]>A[j+1]:
                A[j],A[j+1]=A[j+1],A[j]
                swapped=True
        if not swapped:
            break
    print('After sorting',A)
    
if __name__=='__main__':
    Bubble_sort([i for i in range(10,1,-1)])
    optimised_bubble([i for i in range(20,5,-2)])
