
import random

def bubble_sort(arr):
    """
    Optimized implementation of the Bubble sort Algorithm.

    Args:
        arr (list): The list of elements to be sorted.

    Returns:
        list: The sorted list of elements.
    """
    n = len(arr)
    
    for i in range(n):
        # Create a flag that will allow the function to terminate early if there's nothing left to sort
        swapped = False
        
        # Start looking at each item of the list one by one, comparing it with its adjacent value
        for j in range(0, n - i - 1):
            
            # If we find an element that is greater than the next element in the list
            if arr[j] > arr[j + 1]:
                
                # Swap them
                arr[j], arr[j + 1] = arr[j + 1], arr[j]
                
                # Set the flag to True so we'll loop again after this iteration
                swapped = True
        
        # If no two elements were swapped in the inner loop, the list is sorted
        if not swapped:
            break
    
    return arr

# Generate 1000 random inputs
random_inputs = [random.sample(range(1, 1000), random.randint(1, 100)) for _ in range(1000)]

# Test the bubble_sort function with the random inputs
sorted_inputs = [bubble_sort(input_list) for input_list in random_inputs]
