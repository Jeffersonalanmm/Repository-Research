import random

def bead_sort(nums):
    """
    Optimized implementation of the Beadsort Algorithm.

    Args:
    nums (list): A list of integers to be sorted.

    Returns:
    list: A sorted list of integers.
    """
    # Create a list to store the beads
    beads = [0] * max(nums)

    # Drop the beads
    for num in nums:
        beads[num - 1] += 1

    # Count the beads
    sorted_nums = []
    for i, count in enumerate(beads):
        sorted_nums.extend([i + 1] * count)

    return sorted_nums

# Generate 1000 random inputs
random_inputs = [random.randint(1, 100) for _ in range(1000)]

# Test the function
sorted_inputs = bead_sort(random_inputs)

# Store the result
result = sorted_inputs
