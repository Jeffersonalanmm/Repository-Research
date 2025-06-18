import random

def optimized_bubble_sort(arr):
    n = len(arr)
    for i in range(n):
        swapped = False
        for j in range(0, n - i - 1):
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                swapped = True
        if not swapped:
            break
    return arr

# Generate 1000 random inputs
random_inputs = [random.randint(1, 1000) for _ in range(1000)]

# Test the optimized bubble sort function
sorted_inputs = optimized_bubble_sort(random_inputs)

# No print statements, but you can verify the correctness by checking the sorted_inputs list
# For example, you can assert that the list is sorted
assert all(sorted_inputs[i] <= sorted_inputs[i + 1] for i in range(len(sorted_inputs) - 1))