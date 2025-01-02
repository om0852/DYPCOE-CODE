def binary_search(arr,key):
    arr.sort()
    low=0
    high=len(arr)-1
    while low<=high:
        mid=(low+high)//2
        if(arr[mid]==key):
            print("element found at position",mid)
            return
        elif arr[mid]>key:
            high=mid-1
        else:
            low=mid+1
    print("element not found")
        
    
def menu():
    n=int(input("enter the size of array"))
    arr=[]
    for i in range(0,n):
        n1=int(input("enter a element:"))
        arr.append(n1)
    key = int(input("enter search element"))
    binary_search(arr,key)
    
menu()
        