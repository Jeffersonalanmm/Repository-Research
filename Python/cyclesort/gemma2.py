import random

def cycle_sort(arr):
    n = len(arr)
    for i in range(n):
        if arr[i] != i:
            j = arr[i]
            while arr[j] != j:
                arr[i], arr[j] = arr[j], arr[i]
                j = arr[j]
            arr[i], arr[j] = arr[j], arr[i]
    return arr

# Generate 1000 random inputs
random_array = [random.randint(0, 999) for _ in range(1000)]

# Apply cycle sort
cycle_sorted_array = cycle_sort(random_array.copy()) 