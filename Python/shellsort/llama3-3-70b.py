import random
import time

def shell_sort(arr):
    """
    Optimized implementation of the shell sort algorithm.

    Args:
        arr (list): The list of elements to be sorted.

    Returns:
        list: The sorted list of elements.
    """
    # Initialize the gap size
    gap = len(arr) // 2

    # Loop until the gap size is greater than zero
    while gap > 0:
        # Loop through the array starting from the gap size
        for i in range(gap, len(arr)):
            # Store the current element
            temp = arr[i]

            # Initialize the index for comparison
            j = i

            # Compare and shift elements until the correct position is found
            while j >= gap and arr[j - gap] > temp:
                arr[j] = arr[j - gap]
                j -= gap

            # Place the current element at the correct position
            arr[j] = temp

        # Reduce the gap size by half for the next iteration
        gap //= 2

    return arr


# Generate 1000 random inputs
import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    sorted_arr = shell_sort(arr)


if __name__ == "__main__":
    main()

