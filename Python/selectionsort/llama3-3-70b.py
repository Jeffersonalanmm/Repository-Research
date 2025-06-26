import random
import time

def selection_sort(arr):
    """
    Optimized implementation of the selection sort algorithm.

    Args:
        arr (list): The list of elements to be sorted.

    Returns:
        list: The sorted list of elements.
    """
    # Traverse through all array elements
    for i in range(len(arr)):
        # Initialize the minimum index
        min_index = i
        
        # Find the minimum element in remaining unsorted array
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j
                
        # Swap the found minimum element with the first element of unsorted array
        arr[i], arr[min_index] = arr[min_index], arr[i]
        
    return arr

# Generate 1000 random inputs
random_inputs = [random.randint(1, 1000) for _ in range(1000)]

# Measure the execution time of the selection sort algorithm
start_time = time.time()
sorted_array = selection_sort(random_inputs)
end_time = time.time()

# Calculate the execution time
execution_time = end_time - start_time