def beadsort(arr):
    if not arr:
        return []
    
    max_value = max(arr)
    levels = [[] for _ in range(max_value)]
    
    for idx, num in enumerate(arr):
        for level in range(num):
            levels[level].append(idx)
    
    sorted_indices = []
    for level in levels:
        sorted_indices.extend(level)
    
    return [arr[i] for i in sorted_indices]

# Example usage with 1000 random inputs
import random

random.seed(42)
arr = [random.randint(1, 100) for _ in range(1000)]
sorted_arr = beadsort(arr)