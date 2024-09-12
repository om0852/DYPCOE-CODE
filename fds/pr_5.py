
arr=[10,40,2,0,1]
n=5
def bubble_sort():
    for i in range(0,n-1):
        for j in range(0,n-i-1):
             if(arr[j]>arr[j+1]):
                 arr[j],arr[j+1] = arr[j+1],arr[j]
                 
  
