def bubble_sort(arr):
    """
    Optimized implementation of the Bubble sort Algorithm.

    Args:
    arr (list): The list of elements to be sorted.

    Returns:
    list: The sorted list of elements.
    """
    n = len(arr)

    # Traverse through all array elements
    for i in range(n):
        # Last i elements are already in place
        for j in range(0, n - i - 1):
            # Traverse the array from 0 to n-i-1
            # Swap if the element found is greater than the next element
            if arr[j] > arr[j + 1]:
                arr[j], arr[j + 1] = arr[j + 1], arr[j]

    return arr


import random

# Generate 1000 random integers
arr = [random.randint(0, 1000) for _ in range(1000)]

# Sort the array using bubble sort
sorted_arr = bubble_sort(arr[:])  # Create a copy of the array to avoid modifying the original

# Verify that the array is sorted
assert all(sorted_arr[i] <= sorted_arr[i + 1] for i in range(len(sorted_arr) - 1))