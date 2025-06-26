import random

def selection_sort(arr):
    """
    Sorts an array in ascending order using the selection sort algorithm.

    Args:
        arr (list): The input array to be sorted.

    Returns:
        list: The sorted array.
    """
    # Traverse through all array elements
    for i in range(len(arr)):
        # Find the minimum element in remaining unsorted array
        min_idx = i
        for j in range(i+1, len(arr)):
            if arr[j] < arr[min_idx]:
                min_idx = j
                
        # Swap the found minimum element with the first element of unsorted array        
        arr[i], arr[min_idx] = arr[min_idx], arr[i]
        
    return arr

# Generate 1000 random numbers and sort them
random_inputs = [random.randint(0, 10000) for _ in range(1000)]
sorted_array = selection_sort(random_inputs)