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

