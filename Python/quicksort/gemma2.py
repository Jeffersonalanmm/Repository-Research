
import random

def quick_sort(arr):
    if len(arr) < 2:
        return arr
    pivot = arr[0]
    less = [i for i in arr[1:] if i <= pivot]
    greater = [i for i in arr[1:] if i > pivot]
    return quick_sort(less) + [pivot] + quick_sort(greater)

# Generate 1000 random integers
random_data = [random.randint(1, 1000) for _ in range(1000)]

# Apply quick sort
sorted_data = quick_sort(random_data) 
