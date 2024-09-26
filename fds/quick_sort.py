# Function to perform partition
def partition(arr, low, high):
    pivot = arr[high]  # Select the pivot element
    i = low - 1  # Pointer for the smaller element

    # Traverse through all elements and compare each with the pivot
    for j in range(low, high):
        if arr[j] < pivot:
            i = i + 1  # Increment index of the smaller element
            arr[i], arr[j] = arr[j], arr[i]  # Swap

    # Swap the pivot element with the element at index i + 1
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1  # Return the partition index

# Function to perform quicksort
def quick_sort(arr, low, high):
    if low < high:
        # Find the partition index
        pi = partition(arr, low, high)

        # Recursively sort elements before and after partition
        quick_sort(arr, low, pi - 1)
        quick_sort(arr, pi + 1, high)

# Example usage
arr = [10, 7, 8, 9, 1, 5]
n = len(arr)
quick_sort(arr, 0, n - 1)
print("Sorted array is:", arr)
