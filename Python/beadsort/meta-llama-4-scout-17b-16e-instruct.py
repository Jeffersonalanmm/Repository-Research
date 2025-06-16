
import random

def beadsort(arr):
    """
    Beadsort algorithm implementation.

    :param arr: List of integers to be sorted
    :return: Sorted list of integers
    """
    # Find the maximum value in the array to determine the size of the beads array
    max_val = max(arr)

    # Initialize the beads array with zeros
    beads = [0] * (max_val + 1)

    # Count the occurrence of each value in the input array
    for val in arr:
        beads[val] += 1

    # Calculate cumulative counts
    for i in range(1, len(beads)):
        beads[i] += beads[i - 1]

    # Build the output array
    sorted_arr = [0] * len(arr)
    for val in arr:
        sorted_arr[beads[val] - 1] = val
        beads[val] -= 1

    return sorted_arr


# Generate 1000 random inputs
random_inputs = [random.randint(1, 1000) for _ in range(1000)]

# Run the beadsort algorithm
sorted_outputs = beadsort(random_inputs)

