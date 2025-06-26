
def selection_sort(arr):
    """
    Optimized implementation of the selection sort algorithm.

    Args:
    arr (list): The input list to be sorted.

    Returns:
    list: The sorted list.
    """
    n = len(arr)
    
    # Traverse through all array elements
    for i in range(n):
        
        # Initialize the minimum element index
        min_idx = i
        
        # Find the minimum element in the unsorted part of the array
        for j in range(i+1, n):
            if arr[j] < arr[min_idx]:
                min_idx = j
        
        # Swap the found minimum element with the first element of the unsorted part
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
    
    return arr

import random

# Generate 1000 random integers between 0 and 1000
arr = [random.randint(0, 1000) for _ in range(1000)]

# Sort the array using selection sort
sorted_arr = selection_sort(arr)
