
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

import sys      

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    sorted_arr = bubble_sort(arr)
    print(sorted_arr)

if __name__ == "__main__":
    main()
