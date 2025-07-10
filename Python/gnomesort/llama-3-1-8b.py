
def gnome_sort(arr):
    """
    Gnome sort algorithm implementation.

    Args:
    arr (list): The list of elements to be sorted.

    Returns:
    list: The sorted list of elements.
    """
    if len(arr) <= 1:
        return arr

    pos = 0
    while pos < len(arr):
        if pos == 0 or arr[pos] >= arr[pos - 1]:
            pos += 1
        else:
            arr[pos], arr[pos - 1] = arr[pos - 1], arr[pos]
            if pos > 1:
                pos -= 1
    return arr

# Test the implementation with 1000 random inputs
import random

# Generate 1000 random lists of 100 elements each
random_lists = [[random.randint(0, 1000) for _ in range(100)] for _ in range(1000)]

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
