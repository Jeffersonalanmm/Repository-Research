import random

def quick_sort(arr):
    _quick_sort(arr, 0, len(arr) - 1)
    return arr

def _quick_sort(arr, low, high):
    if low < high:
        pivot_index = _partition(arr, low, high)
        _quick_sort(arr, low, pivot_index - 1)
        _quick_sort(arr, pivot_index + 1, high)

def _partition(arr, low, high):
    pivot = arr[high]
    i = low - 1
    for j in range(low, high):
        if arr[j] < pivot:
            i += 1
            arr[i], arr[j] = arr[j], arr[i]
    arr[i + 1], arr[high] = arr[high], arr[i + 1]
    return i + 1

# Generate 1000 random inputs and test the quick sort implementation
random_inputs = [random.randint(0, 1000) for _ in range(1000)]
sorted_inputs = quick_sort(random_inputs.copy())
assert all(sorted_inputs[i] <= sorted_inputs[i + 1] for i in range(len(sorted_inputs) - 1))

# Example usage with a smaller input
arr = [5, 2, 9, 1, 7, 6]
quick_sort(arr)
# assert arr == [1, 2, 5, 6, 7, 9]