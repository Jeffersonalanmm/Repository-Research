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

# Generate 1000 random inputs
random_inputs = [random.sample(range(1, 1000), random.randint(1, 100)) for _ in range(1000)]

# Test the gnome_sort function with the random inputs
sorted_outputs = [gnome_sort(input_list) for input_list in random_inputs]

# Verify the sorted outputs
for output in sorted_outputs:
    for i in range(len(output) - 1):
        assert output[i] <= output[i + 1], "Output is not sorted"
