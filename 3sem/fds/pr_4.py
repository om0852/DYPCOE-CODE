def menu():
    arr = [30, 20, 1, 5, 34,90]
    ch = 1
    while ch != 4:
        print("################Menu#################")
        print("1. Bubble Sort")
        print("2. Selection Sort")
        print("3.Top 5 scores")
        print("4. Exit")
        ch = int(input("Enter your choice: "))
        if ch == 1:
            bubble_sort(arr)
        elif ch == 2:
            selection_sort(arr)
        elif ch==3:
            print(arr[0:6])
        elif ch==4:
            break
        else:
            print("Invalid Option")

def bubble_sort(arr):
    for i in range(0, len(arr) - 1):
        for j in range(0, len(arr) - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
    print("Sorted array (Bubble Sort):", arr)

def selection_sort(arr):
    for i in range(len(arr) - 1):
        min_index = i
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
        arr[i], arr[min_index] = arr[min_index], arr[i]
    print("Sorted array (Selection Sort):", arr)

menu()
