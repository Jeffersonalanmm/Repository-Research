
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

