
import random

def quicksort(arr):
    """Optimized quicksort implementation with pivot selection and insertion sort for small arrays"""
    if len(arr) <= 1:
        return arr
    return _quicksort_helper(arr, 0, len(arr) - 1)

def _quicksort_helper(arr, low, high):
    """Recursive helper function for quicksort"""
    if low < high:
        if high - low < 10:  # Threshold for switching to insertion sort
            _insertion_sort(arr, low, high)
        else:
            pivot_index = _partition(arr, low, high)
            _quicksort_helper(arr, low, pivot_index - 1)
            _quicksort_helper(arr, pivot_index + 1, high)
    return arr

def _partition(arr, low, high):
    """Partitions the array around a pivot element"""
    # Select the middle element as the pivot
    mid = (low + high) // 2
    if arr[low] > arr[mid]:
        arr[low], arr[mid] = arr[mid], arr[low]
    if arr[mid] > arr[high]:
        arr[mid], arr[high] = arr[high], arr[mid]
    if arr[low] > arr[mid]:
        arr[low], arr[mid] = arr[mid], arr[low]
    
    pivot = arr[mid]
    arr[mid], arr[high] = arr[high], arr[mid]
    
    i = low - 1
    j = high - 1
    k = high
    
    while k > low:
        if arr[k] < pivot:
            i += 1
            arr[i], arr[k] = arr[k], arr[i]
            k -= 1
        elif arr[k] == pivot:
            j += 1
            arr[j], arr[k] = arr[k], arr[j]
            k -= 1
        else:
            k -= 1
    
    return i + 1

def _insertion_sort(arr, low, high):
    """Insertion sort for small arrays"""
    for i in range(low + 1, high + 1):
        key = arr[i]
        j = i - 1
        while j >= low and arr[j] > key:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key

# Example usage with 1000 random inputs
if __name__ == "__main__":
    random.seed(42)
    arr = [random.randint(0, 1000) for _ in range(1000)]
    sorted_arr = quicksort(arr)
