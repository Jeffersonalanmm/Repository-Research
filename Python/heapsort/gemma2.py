
import random

def heapify(arr, n, i):
    largest = i  
    l = 2 * i + 1 
    r = 2 * i + 2 
  
    if l < n and arr[largest] < arr[l]:
        largest = l
  
    if r < n and arr[largest] < arr[r]:
        largest = r
  
    if largest != i:
        arr[i], arr[largest] = arr[largest], arr[i]  
        heapify(arr, n, largest)

def heap_sort(arr):
    n = len(arr)
  
    # Build heap (rearrange array)
    for i in range(n // 2 - 1, -1, -1):
        heapify(arr, n, i)
  
    # One by one extract an element from heap
    for i in range(n - 1, 0, -1):
        arr[0], arr[i] = arr[i], arr[0]  
        heapify(arr, i, 0)

# Generate 1000 random integers
random_numbers = [random.randint(1, 1000) for _ in range(1000)]

# Sort the random numbers using heap sort
heap_sort(random_numbers) 
