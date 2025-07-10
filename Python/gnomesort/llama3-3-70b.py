import random

def gnome_sort(arr):
    """
    Optimized implementation of the Gnome Sort algorithm.

    Args:
        arr (list): The list of integers to be sorted.

    Returns:
        list: The sorted list of integers.
    """
    if len(arr) <= 1:
        return arr

    i = 1
    while i < len(arr):
        if arr[i-1] <= arr[i]:
            i += 1
        else:
            arr[i-1], arr[i] = arr[i], arr[i-1]
            if i > 1:
                i -= 1
    return arr

import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    sorted_arr = gnome_sort(arr)


if __name__ == "__main__":
    main()
