def binary_search(arr, target):
    """
    This function performs a binary search on a sorted array to find the index of the target value.
    
    Args:
        arr (list): A sorted list of elements.
        target (int/float): The value to be searched in the list.
    
    Returns:
        int: The index of the target value if found, otherwise -1.
    """
    low = 0
    high = len(arr) - 1
    
    while low <= high:
        mid = (low + high) // 2  # Using integer division to avoid floating point
        
        if arr[mid] == target:
            return mid
        elif arr[mid] < target:
            low = mid + 1  # Search in the right half
        else:
            high = mid - 1  # Search in the left half
    
    return -1  # Target not found in the array

import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    arr.sort()  # binary_search requires sorted array

    target = 15
    binary_search(arr, target)

if __name__ == "__main__":
    main()
