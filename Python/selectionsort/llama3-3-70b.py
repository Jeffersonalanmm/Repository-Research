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

import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    sorted_arr = selection_sort(arr)


if __name__ == "__main__":
    main()

