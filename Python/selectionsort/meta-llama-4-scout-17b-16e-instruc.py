import random

def selection_sort(arr):
    n = len(arr)
    for i in range(n):
        min_idx = i
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    return arr

# Generate 1000 random inputs
random_inputs = [[random.randint(1, 1000) for _ in range(random.randint(1, 100))] for _ in range(1000)]

# Test the function with the random inputs
for _ in range(len(random_inputs)):
    arr = random_inputs[_]
    sorted_arr = selection_sort(arr)
    assert all(sorted_arr[i] <= sorted_arr[i+1] for i in range(len(sorted_arr)-1))