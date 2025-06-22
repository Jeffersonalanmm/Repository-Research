
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

# Generate 1000 random numbers and sort them using patience sort
random_nums = [random.randint(0, 10000) for _ in range(1000)]
sorted_nums = patience_sort(random_nums)
