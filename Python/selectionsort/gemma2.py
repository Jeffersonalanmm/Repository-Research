
import random

def selection_sort(arr):
  n = len(arr)
  for i in range(n):
    min_idx = i
    for j in range(i+1, n):
      if arr[min_idx] > arr[j]:
        min_idx = j
    arr[i], arr[min_idx] = arr[min_idx], arr[i]
  return arr

# Generate 1000 random integers
random_array = [random.randint(1, 1000) for _ in range(1000)]

# Apply selection sort
selection_sort(random_array) 
