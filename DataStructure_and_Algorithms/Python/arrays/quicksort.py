
#creating function for partitioning
def partition(a,l,h):
    pivot = a[l]        # selecting first element as pivot element
    i = l
    j=h
    while i<j:
        while a[i]<=pivot and i<h: i+=1
        while a[j]>pivot and j>l: j-=1
        if i<j: a[i],a[j]=a[j],a[i]
        
    a[j],a[l]=a[l],a[j]
    return j

#creating recursive function for sorting
def quickSort(a,l,h):
    if l < h:
        pi = partition(a, l, h)
        quickSort(a, l, pi - 1)
        quickSort(a, pi + 1, h)
        
#driver Code        
a =[10, 7, 8, 9, 1, 5 ]
quickSort(a, 0, len(a) - 1)
print(a)

#Output: [1, 5, 7, 8, 9, 10]
