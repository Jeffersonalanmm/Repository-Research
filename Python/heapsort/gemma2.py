
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

import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    sorted_arr = heap_sort(arr)
    
if __name__ == "__main__":
    main()
