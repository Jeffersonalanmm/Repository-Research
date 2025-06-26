import random

def quick_sort(arr):
    """Sorts an array using the quick sort algorithm."""
    _quick_sort_helper(arr, 0, len(arr) - 1)
    return arr

def _quick_sort_helper(arr, low, high):
    """Recursively sorts the array."""
    if low < high:
        pivot_index = _partition(arr, low, high)
        _quick_sort_helper(arr, low, pivot_index - 1)
        _quick_sort_helper(arr, pivot_index + 1, high)

def _partition(arr, low, high):
    """Partitions the array around a pivot."""
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

def generate_random_list(size):
    """Generates a list of random integers."""
    return [random.randint(0, 1000) for _ in range(size)]

# Test the implementation with 1000 random inputs
arr = generate_random_list(1000)
sorted_arr = quick_sort(arr)