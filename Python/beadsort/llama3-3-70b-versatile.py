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


import sys

def main():
    input_path = "inputs.txt" if len(sys.argv) < 2 else sys.argv[1]

    try:
        with open(input_path, 'r') as f:
            nums = []
            for line in f:
                line = line.strip()
                if line.isdigit():
                    nums.append(int(line))
    except FileNotFoundError:
        return

if __name__ == "__main__":
    main()
