
import random

def patience_sort(arr):
    """
    Implementation of the patience sort algorithm.

    Args:
    arr (list): The input list to be sorted.

    Returns:
    list: The sorted list.
    """
    # Initialize piles
    piles = []

    # Iterate over the input list
    for num in arr:
        # Initialize a flag to track if the number is added to a pile
        added = False

        # Iterate over the piles
        for pile in piles:
            # If the number is smaller than or equal to the last element in the pile, add it to the pile
            if num <= pile[-1]:
                pile.append(num)
                added = True
                break

        # If the number is not added to any pile, create a new pile
        if not added:
            piles.append([num])

    # Initialize the result list
    result = []

    # Iterate over the piles and merge them
    while piles:
        # Initialize the minimum value and its index
        min_val = float('inf')
        min_idx = -1

        # Find the pile with the smallest last element
        for i, pile in enumerate(piles):
            if pile[-1] < min_val:
                min_val = pile[-1]
                min_idx = i

        # Add the smallest last element to the result list
        result.append(piles[min_idx].pop())

        # If the pile is empty, remove it
        if not piles[min_idx]:
            piles.pop(min_idx)

    return result


import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            arr = [int(line.strip()) for line in f if line.strip()]
    except FileNotFoundError:
        return

    sorted_arr = patience_sort(arr)
    

if __name__ == "__main__":
    main()