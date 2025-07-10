
import bisect
import random

def patience_sort(nums):
    """
    Patience sort algorithm implementation.

    Args:
    - nums (list): A list of integers to be sorted.

    Returns:
    - list: A sorted list of integers.
    """
    piles = []
    for num in nums:
        # Find the index of the first pile that is greater than or equal to num
        idx = bisect.bisect_left([pile[-1] for pile in piles], num)
        if idx == len(piles):
            # If num is greater than all existing piles, create a new pile
            piles.append([num])
        else:
            # Otherwise, add num to the appropriate pile
            piles[idx].append(num)
    
    # Merge the piles into a single sorted list
    sorted_nums = []
    while piles:
        min_val = float('inf')
        min_idx = -1
        for i, pile in enumerate(piles):
            if pile[-1] < min_val:
                min_val = pile[-1]
                min_idx = i
        sorted_nums.append(min_val)
        piles[min_idx].pop()
        if not piles[min_idx]:
            del piles[min_idx]
    
    return sorted_nums[::-1]

import random
import bisect

def patience_sort(arr):
    piles = []
    for x in arr:
        i = bisect.bisect_left(piles, x)
        if i != len(piles):
            piles[i] = x
        else:
            piles.append(x)
    return piles

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