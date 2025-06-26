import random

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]

# Generate 1000 random integers
random_inputs = [random.randint(0, 10000) for _ in range(1000)]

# Sort the list using selection sort
selection_sort(random_inputs)