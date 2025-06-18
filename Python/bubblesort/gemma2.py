import random

def bubble_sort(arr):
  n = len(arr)
  for i in range(n):
    swapped = False
    for j in range(0, n-i-1):
      if arr[j] > arr[j+1]:
        arr[j], arr[j+1] = arr[j+1], arr[j]
        swapped = True
    if not swapped:
      break
  return arr

# Generate 1000 random integers
data = [random.randint(1, 1000) for _ in range(1000)]

# Sort the data using bubble sort
sorted_data = bubble_sort(data.copy()) 
