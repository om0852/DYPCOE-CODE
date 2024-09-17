def menu():
   arr=[30,20,1,5,34]
   ch=1
   while ch!=3:
    print("################Menu#################")
    print("1.Bubble Sort")
    print("2.Selection Sort")
    print("3.Exit")
    ch=int(input("Enter your choice"))
    if ch==1:
        bubble_sort(arr)
    elif ch==2:
        selection_sort(arr)
    else:
      break
  
def bubble_sort(arr):
    for i in range(0,len(arr)-1):
        l=(len(arr)-i-1)
        for j in range(0,l):
            if arr[j]>arr[j+1]:
                  arr[j],arr[j+1]=arr[j+1],arr[j]
    print(arr)
    
menu()