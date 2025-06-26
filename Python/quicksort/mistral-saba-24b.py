import random

def quick_sort(arr):
    if len(arr) <= 1:
        return arr
    else:
        pivot = arr[len(arr) // 2]
        left = [x for x in arr if x < pivot]
        middle = [x for x in arr if x == pivot]
        right = [x for x in arr if x > pivot]
        return quick_sort(left) + middle + quick_sort(right)

# Generate 1000 random inputs
random_inputs = [random.randint(1, 10000) for _ in range(1000)]

# Sort the random inputs using quick sort
sorted_inputs = quick_sort(random_inputs)